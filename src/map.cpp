
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
        return sprites::WALL1;
    }

    return TILES[gx + gy*MAP_WIDTH];
}

bool isTilePassable(uint8_t tileType, Dir dir) {
    (void) dir;
    switch( tileType ){
        // solid which cannot be entered from any side:
        case sprites::WALL1:
        case sprites::WALL2:
        case sprites::WALL3:
        case sprites::WALL4:
        case sprites::WALL5:
        case sprites::WALL6:
        case sprites::WALL7:
        case sprites::WALL8:
        case sprites::WALL9:
        case sprites::WALL10:
        case sprites::WALL11:
        case sprites::WALL12:
        case sprites::WALL13:
        case sprites::FURN1:
        case sprites::FURN2:
        case sprites::FURN3:
        case sprites::FURN4:
        case sprites::FURN5:
        case sprites::FURN6:
        case sprites::FURN7:
        case sprites::FURN8:
        case sprites::FURN9:
        case sprites::FURN10:
        case sprites::FURN11:
        case sprites::FURN12:
        case sprites::FURN13:
        case sprites::FURN14:
        case sprites::FURN15:
        case sprites::FURN16:
        case sprites::FURN17:
        case sprites::FURN18:
        case sprites::PINETREE:
            return false;

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
