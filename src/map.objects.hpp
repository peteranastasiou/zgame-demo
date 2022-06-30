
#pragma once

#include "map.hpp"
#include "sprites.hpp"
#include "gameloop.hpp"
#include "window.dialogue.hpp"

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

    virtual char const * getLabel() override {
        return "";
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

    void setTriggered(bool triggered){ triggered_= triggered; }
    bool isTriggered(){ return triggered_; }

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

// class Sconce : public TriggeredObject {
// public:
//     virtual bool passable() override { return false; }

//     virtual bool onInteraction() override {
//         static bool doOnce = true;
//         doOnce = false;
//         return true;
//     }

//     virtual void render(int cycle, int x, int y) override {
//         *DRAW_COLORS = 0x1204;
//         if( triggered_ ){
//             render_( sprites::SCONCE_LIT1, x, y, cycle % 2 ? BLIT_FLIP_X : 0);
//         }else{
//             render_( sprites::SCONCE_UNLIT, x, y);
//         }
//     }
// };

class Npc : public Object {
public:
    Npc(uint8_t sprite, char const * name, Dialogue * dialogue){
        sprite_ = sprite;
        dialogue_ = dialogue;
        name_ = name;
    }

    virtual void render(int cycle, int x, int y) override {
        (void) cycle;
        *DRAW_COLORS = 0x0234;
        render_(sprite_, x, y, 0);
    }

    virtual char const * getLabel() override {
        return name_;
    }

    virtual void update(int tick) override {
        (void) tick;
    }

    virtual bool passable() override {
        return false;
    }

    virtual void interact() override {
        gameloop::pushWindow(dialogue_);
    }

    virtual void store(uint8_t *& ptr) override {
        (void) ptr;
    }

    virtual void load(uint8_t *& ptr) override {
        (void) ptr;
    }
private:
    uint8_t sprite_;
    char const * name_;
    Dialogue * dialogue_;
};

// class Gate : public TriggeredObject {
// public:
//     virtual bool passable() override { return triggered_; }

//     virtual bool onInteraction() override {
//         return false;
//     }

//     virtual void render(int cycle, int x, int y) override {
//         (void) cycle;
//         *DRAW_COLORS = 0x0234;
//         if( !triggered_ ) {
//             render_(sprites::GATE, x, y);
//         }
//     }
// };

} // namespace map
