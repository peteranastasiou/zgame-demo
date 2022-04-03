
#pragma once

#include "map.hpp"
#include "sprites.hpp"

namespace map {

// ------------------------------------------------------------------
// Some partially-complete object super classes which should be handy:
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

class TriggeredObject : public Object
{
protected:
    bool triggered_= false;

public:
    // Implement this to customise interaction
    virtual bool onInteraction()=0;

    virtual void update(int tick) override {
        (void) tick;
    }

    virtual void interact() override {
        if( triggered_ ) return;

        if( onInteraction() ) triggered_= true;
    }

    virtual void store(uint8_t *& ptr) override {
        *ptr++ = (uint8_t)triggered_;
    }

    virtual void load(uint8_t *& ptr) override {
        triggered_= (uint8_t)*ptr++;
    }
};

// ------------------------------------------------------------------
// Custom objects for the game
// ------------------------------------------------------------------

class Sconce : public TriggeredObject
{
public:
    virtual bool passable() override {
        return false;
    }

    virtual bool onInteraction() override {
        // TODO enqueue dialogue
        trace("Sconce lit\n");
        return true;
    }

    virtual void render(int cycle, int ox, int oy) override {
        *DRAW_COLORS = 0x1204;
        if( triggered_ ){
            render_( cycle % 2 ? sprites::SCONCE_LIT1 : sprites::SCONCE_LIT2, ox, oy);
        }else{
            render_( sprites::SCONCE_UNLIT, ox, oy);
        }
    }
};


} // namespace map
