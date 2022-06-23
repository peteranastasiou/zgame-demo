
#include "dir.hpp"
#include "map.hpp"
#include "map.objects.hpp"
#include "map.impl.auto.hpp"
#include "map.rooms.hpp"
#include "config.hpp"
#include "sprites.hpp"


namespace map {

void init() {
    initObjects();
}

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
    for( int tx = 0; tx < SCREEN_WIDTH; ++tx ){
        for( int ty = 0; ty < SCREEN_HEIGHT; ++ty ){
            Object * obj = getObject(ox + tx, oy + ty);
            if( obj != nullptr ){
                obj->render(cycle, tx, ty);
            }
        }
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
    if( gx < 0 || gy < 0 || gx >= MAP_WIDTH || gy >= MAP_HEIGHT){
        // out of bounds
        return nullptr;
    }

    return OBJECTS[gx + MAP_WIDTH * gy];
}

} // namespace map
