
#pragma once

#include "map.hpp"
#include "sprites.hpp"
#include "gameloop.hpp"
#include "window.dialogue.hpp"
#include "audio.system.hpp"

namespace map {

// ------------------------------------------------------------------
// Some partially-complete object super classes which should be handy:
// ------------------------------------------------------------------

class SimpleObject : public Object {
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

class TriggeredObject : public Object {
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

class ToggledObject : public Object {
protected:
    bool triggered_= false;

public:
    // Implement this to customise interaction
    virtual bool onInteraction()=0;

    virtual void update(int tick) override {
        (void) tick;
    }

    virtual void interact() override {
        if( onInteraction() ) triggered_= !triggered_;
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

static Dialogue hutMsg("A tiny yurt is hidden in this alcove.\nYou may rest here.");
class Hut : public SimpleObject {
    virtual void interact() override {
        gameloop::pushWindow(&hutMsg);
    }

    virtual void render(int cycle, int ox, int oy) override {
        (void) cycle;
        *DRAW_COLORS = 0x1234;
        render_( sprites::HUT, ox, oy);
    }
};

static Dialogue sconceMsg("A spark leaps from your ELECTRIC CLOAK and sets the sconce ablaze.");

class Sconce : public TriggeredObject {
public:
    virtual bool passable() override { return false; }

    virtual bool onInteraction() override {
        static bool doOnce = true;
        if( doOnce ) gameloop::pushWindow(&sconceMsg);
        doOnce = false;
        return true;
    }

    virtual void render(int cycle, int ox, int oy) override {
        *DRAW_COLORS = 0x1204;
        if( triggered_ ){
            render_( sprites::SCONCE_LIT1, ox, oy, cycle % 2 ? BLIT_FLIP_X : 0);
        }else{
            render_( sprites::SCONCE_UNLIT, ox, oy);
        }
    }
};

class MushroomsPickup : public TriggeredObject {
public:
    virtual bool passable() override { return true; }

    virtual bool onInteraction() override {
        // TODO enqueue dialogue, add to inventory
        trace("Pickup\n");
        return true;
    }

    virtual void render(int cycle, int ox, int oy) override {
        (void) cycle;
        *DRAW_COLORS = 0x0234;
        if( !triggered_ ) {
            // dance
            uint32_t flags = 0;
            render_( sprites::MUSHROOMS, ox, oy, flags);
        }
    }
};

static Dialogue guardMsg("The guard blocks your passage.");
static Dialogue guardMsg2("10 STR required");

class Knight : public TriggeredObject {
public:
    virtual bool passable() override { return triggered_; }

    virtual bool onInteraction() override {

        //TODO enqueue battle screen
        tracef("msg1 %x", (int)(&guardMsg));
        tracef("msg2 %x", (int)(&guardMsg2));
        gameloop::pushWindow(&guardMsg);
        gameloop::pushWindow(&guardMsg2);
        return false;
    }

    virtual void render(int cycle, int ox, int oy) override {
        (void) cycle;
        *DRAW_COLORS = 0x0234;
        if( !triggered_ ) {
            render_( sprites::KNIGHT1, ox, oy, (cycle/2) % 2 ? BLIT_FLIP_X : 0);
        }
    }
};

class Snake : public TriggeredObject {
public:
    virtual bool passable() override { return triggered_; }

    virtual bool onInteraction() override {
        // TODO enqueue battle screen
        trace("Fight!\n");
        return false;
    }

    virtual void render(int cycle, int ox, int oy) override {
        (void) cycle;
        *DRAW_COLORS = 0x0234;
        if( !triggered_ ) {
            // sequence
            int sprite=0;
            switch( (cycle/2) % 4 ){
                case 0: sprite= sprites::SNAKE1; break;
                case 1: sprite= sprites::SNAKE2; break;
                case 2: sprite= sprites::SNAKE1; break;
                case 3: sprite= sprites::SNAKE3; break;
            }
            render_( sprite, ox, oy);
        }
    }
};

class Egg : public TriggeredObject {
public:
    virtual bool passable() override { return triggered_; }

    virtual bool onInteraction() override {
        return false;
    }

    virtual void render(int cycle, int ox, int oy) override {
        (void) cycle;
        *DRAW_COLORS = 0x0234;
        if( !triggered_ ) {
            render_( (cycle/2) % 2 ? sprites::EGG1 : sprites::EGG2, ox, oy);
        }
    }
};

static Dialogue jukeMsg1("You turn the jukebox on. The developer's attempt at a tune assalts your senses.");
static Dialogue jukeMsg2("You turn that mess off.");
class Jukebox : public ToggledObject {
public:
    virtual bool passable() override { return false; }

    virtual bool onInteraction() override {
        if( triggered_ ){
            // turn off
            gameloop::pushWindow(&jukeMsg2);
            audio::demoStop();
        }else{
            // turn on
            audio::demo();
            gameloop::pushWindow(&jukeMsg1);
        }
        return true;
    }

    virtual void render(int cycle, int ox, int oy) override {
        (void) cycle;
        *DRAW_COLORS = 0x1034;
        uint32_t flags = 0;
        if( triggered_ ) flags = cycle % 2 ? BLIT_FLIP_X : 0;
        render_( sprites::JUKEBOX, ox, oy, flags);
    }
};

static Dialogue wallMsg1("Pressing a concealed button, you slip through the false wall.");
class FalseWall : public SimpleObject {
public:
    virtual bool passable() override { return true; }

    virtual void interact() override {
        gameloop::pushWindow(&wallMsg1);
    }

    virtual void render(int cycle, int ox, int oy) override {
        (void) cycle;
        *DRAW_COLORS = 0x1234;
        render_( sprites::STONE_WALL, ox, oy);
    }
};

} // namespace map
