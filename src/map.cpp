#include "map.hpp"
#include "objects.hpp"
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

Sconce sconce1;

static Object * const OBJECTS[]= {
    &sconce1
};

#define NUM_OBJECTS 1

void render(int sx, int sy, uint32_t tick)
{
    (void) tick;
    // origin (in tiles)
    int ox = sx*SCREEN_WIDTH;
    int oy = sy*SCREEN_HEIGHT;

    // draw background
    *DRAW_COLORS = 0x1234;
    for( int tx = 0; tx < SCREEN_WIDTH; ++tx ){
        for( int ty = 0; ty < SCREEN_HEIGHT; ++ty ){
            Tile tile = getTile(ox + tx, oy + ty);
            sprites::blit(tile.sprite, 16*tx, 16*ty);
        }
    }

    // animation cycle is slower than ticks
    int cycle = tick / 4;

    // draw foreground (objects)
    for( int objIdx = 0; objIdx < NUM_OBJECTS; ++objIdx ){
        Object * obj = OBJECTS[objIdx];
        // check on current screen  -- TODO make this better
        if( obj->x <= ox 
         || obj->y <= oy
         || obj->x > ox+SCREEN_WIDTH 
         || obj->y > oy+SCREEN_HEIGHT ) continue;

        obj->render(cycle, ox, oy);
    }
}

// first checks object list, then tile
bool interact(int gx, int gy)
{
    // TODO check object first
    bool obj_passable = true;

    // then check tile
    Tile tile = getTile(gx, gy);

    // both object and tile need to be passable, to pass
    return obj_passable && tile.passable;
}

Tile getTile(int gx, int gy)
{
    if( gx < 0 || gy < 0 || gx >= MAP_WIDTH || gy >= MAP_HEIGHT){
        // should never happen
        return {};
    }

    uint8_t tile = TILES[gx + gy*MAP_WIDTH];
    // cast to Tile struct:
    return *(Tile*) &tile;
}

} // namespace map
