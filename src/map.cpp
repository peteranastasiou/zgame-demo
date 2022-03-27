#include "map.hpp"
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
