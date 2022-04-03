
#pragma once

#include "sprites.hpp"
#include "wasm4.h"
#include <stdint.h>

namespace map {

// ------------------------------------------------------------------//
// Background is made of tiles
// ------------------------------------------------------------------//
struct Tile
{
    uint8_t sprite:7;
    uint8_t passable:1; // last bit=MSB, assuming little-endian (true for wasm)
};

static_assert(sizeof(Tile) == 1, "check sizeof(Tile) 1 byte");

// ------------------------------------------------------------------//
// Foreground is made of objects
// ------------------------------------------------------------------//

/** 
 * Object interface:
 */
class Object
{
public:
    int x;
    int y;

    // called to check if can walk into this tile
    virtual bool passable()=0;
    
    // called when entering the tile (if passable) or bumping (if not passable)
    virtual void interact()=0;

    // called once a while (how often?)
    virtual void update(int tick)=0;

    // called to check what sprite to draw. 
    // cycle is slower than ticks and defines animation speed
    virtual int render(int cycle)=0;

    // place data into ptr and increment it
    virtual void store(uint8_t *& ptr)=0;

    // load data from ptr and increment it
    virtual void load(uint8_t *& ptr)=0;

protected:
    void render_(int sprite, uint32_t flags=0){
        sprites::blit(sprite, 16*x, 16*y, flags);
    }
};

// ------------------------------------------------------------------
// Some partially-complete super classes which should be handy:
// ------------------------------------------------------------------

class SimpleObject : public Object
{
public:
    virtual bool passable() override {
        return false;
    }
    
    virtual void interact() override {
    }

    virtual void update(int tick) override {
        (void) tick;
    }

    virtual void store(uint8_t *& ptr) override {
        (void) ptr;
    }

    virtual void load(uint8_t *& ptr) override {
        (void) ptr;
    }
};

/**
 * Triggered object has a single flag which fires once, on interaction
 */
class TriggeredObject : public Object
{
protected:
    bool triggered= false;

    // Implement this to customise interaction
    virtual bool onInteraction()=0;

public:
    virtual void update(int tick) override {
        (void) tick;
    }

    virtual void interact() override {
        if( triggered ) return;

        if( onInteraction() ) triggered= true;
    }

    virtual void store(uint8_t *& ptr) override {
        *ptr++ = (uint8_t)triggered;
    }

    virtual void load(uint8_t *& ptr) override {
        triggered= (uint8_t)*ptr++;
    }
};


// ----------------------------------------------
// Alternative idea:
// Function struct, external 1 byte state
// This allows for mix and match reuse of functions
// External state means easy store/load (could be array of state)
typedef bool (*PassableFunc)(uint8_t & state);
typedef void (*OnInteractionFunc)(uint8_t & state);
typedef void (*RenderFunc)(uint8_t & state, int tick);

struct FObject
{
    int x;
    int y;
    PassableFunc passable;
    OnInteractionFunc onInteraction;
    RenderFunc render;
};

// Functions specified by Tiled
// Auto-coded like so:
// FObject const OBJECTS = {
//     {1, 1, impassable, sconceInteract, sconceRender},  // sconce instance
//     {2, 2, doorPassable, doorInteract, doorRender}     // door instance
//};
// ----------------------------------------------



// ----------------------------------------------
// Map Functions
// ----------------------------------------------

/**
 *  first checks object list, then tile
 * @param sx screen coord
 * @param sy screen coord
 */
void render(int sx, int sy, uint32_t tick);

/**
 *  first checks object list, then tile
 * @param gx global tile coord
 * @param gy global tile coord
 * @param returns true if passable
 */
bool interact(int gx, int gy);

/**
 * get tile and whether passable
 * @param gx global tile coord
 * @param gy global tile coord
 */
Tile getTile(int gx, int gy);


} // namespace map