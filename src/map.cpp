
#include "dir.hpp"
#include "map.hpp"
#include "map.objects.hpp"
#include "map.impl.auto.hpp"
#include "config.hpp"
#include "sprites.hpp"

/**
 * puzzles to test system:
 * SINGLE OBJECT:
 *  - light sconce
 *  - 
 *  - pick up into inventory (todo)
 *  - obstacle e.g. mob or ability check - triggers screen, then changes object
 *  - interaction triggers "animation" e.g. moving obstacle
 *  - warps
 *  - picking up treasure causes mob to appear OR recorded in blackboard that a mob is hunting you
 * MANY TO ONE:
 *  - light all sconces to get a pickup appear, when get pickup, door is unlocked
 * ONE TO MANY:
 *  - destruction of statue causes cultists to flee
 *  - opening one sarcophagus causes all to open
 * 
 * 
 * TODO expand objects array out to a map at runtime to reduce comparisons?
 * 
 */

namespace map {

void render(int sx, int sy, uint32_t tick) {
    // origin (in tiles)
    int ox = sx*SCREEN_WIDTH;
    int oy = sy*SCREEN_HEIGHT;

    // draw background
    *DRAW_COLORS = 0x1234;
    for( int tx = 0; tx < SCREEN_WIDTH; ++tx ){
        for( int ty = 0; ty < SCREEN_HEIGHT; ++ty ){
            uint8_t tile = getTile(ox + tx, oy + ty);
            sprites::blit(tile, 16*tx, 16*ty);
        }
    }

    // animation cycle is slower than ticks
    int cycle = tick / 4;

    // draw foreground (objects)
    for( int objIdx = 0; objIdx < NUM_OBJECTS; ++objIdx ){
        Object * obj = OBJECTS[objIdx];
        // check if on current screen  -- TODO make this better
        if( obj->x < ox 
         || obj->y < oy
         || obj->x >= ox+SCREEN_WIDTH 
         || obj->y >= oy+SCREEN_HEIGHT ) continue;

        obj->render(cycle, ox, oy);
    }
}

// first checks object list, then tile
bool interact(int gx, int gy, Dir dir) {
    // check object first
    Object * obj = getObject(gx, gy);
    if( obj ){
        // check if passable first, in case interact() changes it
        bool passable = obj->passable();
        // TODO pass dir to object
        obj->interact();
        if( !passable ) return false;
    }

    // then check tile
    return isTilePassable(getTile(gx, gy), dir);
}

uint8_t getTile(int gx, int gy) {
    if( gx < 0 || gy < 0 || gx >= MAP_WIDTH || gy >= MAP_HEIGHT){
        // out of bounds
        return sprites::STONE_WALL;
    }

    return TILES[gx + gy*MAP_WIDTH];
}

bool isTilePassable(uint8_t tileType, Dir dir) {
    switch( tileType ){
        // solid which cannot be entered from any side:
        case sprites::STONE_WALL:
        case sprites::STONE_WALL_LIGHT:
        case sprites::STONE_WALL_DARK:
        case sprites::TREE:
        case sprites::CELL_NESW:
            return false;

        // "Cells" are thin walled tiles which may be entered from some sides:
        // Note that dir is the approach direction, which is opposite to the side of the cell!
        case sprites::CELL_N:  return dir != Dir::S;
        case sprites::CELL_E:  return dir != Dir::W;
        case sprites::CELL_S:  return dir != Dir::N;
        case sprites::CELL_W:  return dir != Dir::E;

        case sprites::CELL_NE:  return dir != Dir::S && dir != Dir::W;
        case sprites::CELL_NW:  return dir != Dir::S && dir != Dir::E;
        case sprites::CELL_SE:  return dir != Dir::N && dir != Dir::W;
        case sprites::CELL_SW:  return dir != Dir::N && dir != Dir::E;
        case sprites::CELL_NS:  return dir != Dir::N && dir != Dir::S;
        case sprites::CELL_EW:  return dir != Dir::E && dir != Dir::W;

        case sprites::CELL_ESW:  return dir == Dir::S;
        case sprites::CELL_SWN:  return dir == Dir::W;
        case sprites::CELL_WNE:  return dir == Dir::N;
        case sprites::CELL_NES:  return dir == Dir::E;

        default:  return true;
    }
}

Object * getObject(int gx, int gy) {
    // TODO Expand to array so this is O(1) not O(n)
    for( Object * obj : OBJECTS ){
        if( obj->x == gx && obj->y == gy ){
            return obj;
        }
    }
    return nullptr;
}

} // namespace map
