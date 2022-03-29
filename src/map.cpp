#include "map.hpp"
#include "map.impl.auto.hpp"
#include "config.hpp"
#include "sprites.hpp"

namespace map {
/**
 * NOTES: save/load game by passing a pointer by each tile, giving each a chance to store/load from it
 *        that way, stateless tiles can ignore it and not use up the 1k space
 * 
 * TODO object layer and background layer. object layer can be a list of points, rather than grid?
 * background layer is simply passable or not,
 * or: store single tile as "background" for each screen, then just need one map?
 *
 * puzzles to test system:
 * SINGLE OBJECT:
 *  - light candelabra
 *  - 
 *  - pick up into inventory (todo)
 *  - obstacle e.g. mob or ability check - triggers screen, then changes object
 *  - interaction triggers "animation" e.g. moving obstacle
 *  - warps
 *  - picking up treasure causes mob to appear OR recorded in blackboard that a mob is hunting you
 * MANY TO ONE:
 *  - light all candelabra to get a pickup appear, when get pickup, door is unlocked
 * ONE TO MANY:
 *  - destruction of statue causes cultists to flee
 *  - opening one sarcophagus causes all to open
 * 
 */

void render(uint8_t sx, uint8_t sy, uint32_t tick)
{
    // TODO screens 
    (void) sx;
    (void) sy;
    (void) tick;

    // draw background
    *DRAW_COLORS = 0x1234;
    for( int ii = 0; ii < map_height; ++ii ){
        for( int jj = 0; jj < map_width; ++jj ){
            uint8_t t = tiles[jj*map_width + ii];
            uint8_t spriteIdx = t & 0x7F;
            sprites::blit(spriteIdx, 16*ii, 16*jj);
        }
    }

    // draw foreground (objects)
}

// first checks object list, then tile
bool interact(int gx, int gy)
{
    tracef("interact %d %d", gx, gy);
    if( gx < 0 || gy < 0 || gx >= map_width || gy >= map_height) return false;

    // todo check object first
    bool obj_passable = true;

    // then check tile
    uint8_t t = tiles[gy*map_width + gx];
    tracef("tile %d: %d -- %d\n", gy*map_width + gx, t, t&0x80);
    bool tile_passable = (t & 0x80) != 0;

    return obj_passable && tile_passable;
}

/*
class GenericTile: public Tile {
private:
    uint8_t sprite_;
    bool passable_;

public:
    GenericTile(uint8_t sprite, bool passable): 
        sprite_(sprite), passable_(passable) {
    }
    virtual bool passable() override{
        return passable_;
    }
    virtual void interact() override{
    }
    virtual void store(uint8_t ** ptr) override{
        (void) ptr;
    }
    virtual void load(uint8_t ** ptr) override{
        (void) ptr;
    }
    virtual uint8_t sprite(int cycle) override{
        (void) cycle;
        return sprite_;
    }
};

struct DoorTile: public Tile {
    uint8_t spriteClosed, spriteOpened;
    bool open;

    virtual bool passable() override{
        return !open;
    }
    virtual void interact() override{
        // check blackboard if have key
    }
    virtual uint8_t sprite(int cycle) override{
        (void) cycle;
        return open ? spriteOpened : spriteClosed;
    }
};

struct DoorTile: public Tile {
    uint8_t spriteClosed, spriteOpened;
    bool open;

    virtual bool passable() override{
        return !open;
    }
    virtual void interact() override{
        // check blackboard if have key
    }
    virtual uint8_t sprite(int cycle) override{
        (void) cycle;
        return open ? spriteOpened : spriteClosed;
    }
};

static GenericTile brickWall(sprites::COBBLESTONE, false); // shared object
static DoorTile door; // unique object

Tile * tiles[]= {
    &wall1, &door1, 
};


Tile * get(uint8_t x, uint8_t y)
{
    return tiles;
}
*/
}
