
#include "gameloop.hpp"
#include "wasm4.h"
#include "window.menu.hpp"
#include "window.dialogue.hpp"
#include "config.hpp"
#include "sprites.hpp"
#include "map.hpp"
#include "map.rooms.hpp"
#include "str.hpp"
#include "queue.hpp"

namespace gameloop {

enum class State {
    MENU, RUNNING, WINDOW
};

enum class EventType {
    WINDOW,
    TRIGGER_OBJECT
};

struct Event {
    EventType type;
    void * object;  // Window or map::Object
};

// hack!
static bool gameStarted_ = false;

class Title : public Window {
public:
    Title() {}

    virtual void reset() override {}

    // true means window is closing
    virtual bool update() override {
        if( gameloop::wasPressed(BUTTON_2) ){
            gameStarted_ = true;
            return true;
        }
        return false;
    }

    virtual void render(uint32_t tick) override {
        (void) tick;
        // origin of title hidden in the map data (in tiles)
        int ox = 30;
        int oy = 0;

        // draw background
        *DRAW_COLORS = 0x1234;
        for( int tx = 0; tx < 10; ++tx ){
            for( int ty = 0; ty < 10; ++ty ){
                uint8_t tile = map::getTile(ox + tx, oy + ty);
                sprites::blit(tile, 16*tx, 16*ty);
            }
        }
    }
};
static Title title;

Hero hero(7, 27);

static State state= State::RUNNING;
static uint32_t tick= 0;
static Queue<Event, 8> eventQueue;
static Window * currentWindow;

// Gamepad state
static uint8_t previousGamepad= 0;
static uint8_t currentGamepad= 0;
static uint8_t pressedThisFrame= 0;

bool wasPressed(uint8_t btn){
    return pressedThisFrame & btn;
}

bool isPressed(uint8_t btn){
    return currentGamepad & btn;
}

void init(){
    pushWindow(&title);
}

void update(){
    // Update input
    currentGamepad = *GAMEPAD1;
    pressedThisFrame = currentGamepad & (currentGamepad ^ previousGamepad);
    previousGamepad = currentGamepad;

    // If we are ready for it, and one is available: grab the next window to display
    if( state == State::RUNNING && !eventQueue.isEmpty() ){
        Event evt = eventQueue.pop();
        if( evt.type == EventType::WINDOW ){
            currentWindow = (Window *)evt.object;
            currentWindow->reset();
            state = State::WINDOW;
        }else if( evt.type == EventType::TRIGGER_OBJECT ) {
            map::Object * obj = (map::Object *)evt.object;
            obj->setTriggered(true);
        }
    }

    // What map screen are we on:
    int screenX = hero.getX()/10;
    int screenY = hero.getY()/10;

    // Render everything
    map::render(screenX, screenY, tick);
    hero.render(tick);

    // Screen specific update function
    map::update(screenX, screenY, tick);

    // top banner
    *DRAW_COLORS = 0x0044;
    rect(0, 0, SCREEN_SIZE, 16);

    // Game state machine
    if( state == State::RUNNING ){
        // room label
        *DRAW_COLORS = 0x0041;
        text(map::getRoomLabel(screenX, screenY), 3, 3);

        // Manage player character
        hero.update(tick);

    }else if( state == State::WINDOW ){
        // Label the facing object
        // Dir dir = hero.getDir();
        // int facingTileX = hero.getX() + dirGetX(dir);
        // int facingTileY = hero.getY() + dirGetY(dir);
        // map::Object * obj = map::getObject(facingTileX, facingTileY);

        // if( obj ){
        //     *DRAW_COLORS = 0x0044;
        //     rect(0, 0, SCREEN_SIZE, 16);
        //     *DRAW_COLORS = 0x0041;
            
        //     text(obj->getLabel(), 3, 3);
        //     // TODO centre ^^
        // }

        // render the window
        currentWindow->render(tick);

        // close the window if done
        if( currentWindow->update() ) state= State::RUNNING;
    }

    tick ++;
}

void pushWindow(Window * window) {
    Event evt;
    evt.type = EventType::WINDOW;
    evt.object = window;
    eventQueue.push(evt);
}

void pushObjectToTrigger(map::Object * object) {
    Event evt;
    evt.type = EventType::TRIGGER_OBJECT;
    evt.object = object;

    // check if already in queue to be triggered:
    for(int i = 0; i < eventQueue.getSize(); i++){
        Event e = eventQueue.at(i);
        if( e.type == evt.type && e.object == evt.object ){
            // already in queue, don't double up!
            return;
        }
    }

    tracef("Push to trigger '%s'", object->getLabel());
    eventQueue.push(evt);
}


} // namespace gameloop
