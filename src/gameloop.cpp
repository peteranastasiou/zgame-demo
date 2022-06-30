
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

Hero hero(2, 5);

static State state= State::RUNNING;
static uint32_t tick= 0;
static Queue<Window *, 8> windowQueue;
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

void update(){
    // Update input
    currentGamepad = *GAMEPAD1;
    pressedThisFrame = currentGamepad & (currentGamepad ^ previousGamepad);
    previousGamepad = currentGamepad;

    // If we are ready for it, and one is available: grab the next window to display
    if( state == State::RUNNING && !windowQueue.isEmpty() ){
        currentWindow = windowQueue.pop();
        currentWindow->reset();
        state = State::WINDOW;
    }

    // What map screen are we on:
    int screenX = hero.getX()/10;
    int screenY = hero.getY()/10;

    // Render everything
    map::render(screenX, screenY, tick);
    hero.render(tick);

    // Screen specific update function
    map::update(screenX, screenY, tick);

    // Game state machine
    switch( state ){
        default:
        case State::RUNNING:{
            // Manage player character
            hero.update(tick);
            break;
        }
        case State::WINDOW:{
            currentWindow->render(tick);

            // close the window if done
            if( currentWindow->update() ) state= State::RUNNING;
            break;
        }
    }

    // Debug info
    if( isPressed(BUTTON_LEFT) && isPressed(BUTTON_RIGHT) ){
        // show player position on screen:
        *DRAW_COLORS = 0x0041;
        StrBuffer<8> str;
        str.appendUint8((uint8_t)hero.getX());
        str.append(',');
        str.appendUint8((uint8_t)hero.getY());
        text(str.get(), 0, 1);
    }

    // HUD for facing objects
    Dir dir = hero.getDir();
    int facingTileX = hero.getX() + dirGetX(dir);
    int facingTileY = hero.getY() + dirGetY(dir);
    map::Object * obj = map::getObject(facingTileX, facingTileY);

    if( obj ){
        *DRAW_COLORS = 0x0044;
        rect(0, 0, SCREEN_SIZE, 9);
        *DRAW_COLORS = 0x0041;
        text(obj->getLabel(), 1, 1);
    }
    // TODO do this on room change only, and disappear after a few frames
    //else{
    //     rect(0, 0, SCREEN_SIZE, 9);
    //     *DRAW_COLORS = 0x0041;
    //     text(map::getRoomLabel(screenX, screenY), 1, 1);
    // }

    tick ++;
}

void pushWindow(Window * window) {
    windowQueue.push(window);
}

} // namespace gameloop
