
#include "gameloop.hpp"
#include "wasm4.h"
#include "audio.system.hpp"
#include "hero.hpp"
#include "config.hpp"
#include "sprites.hpp"
#include "map.hpp"
#include "str.hpp"
#include "queue.hpp"

namespace gameloop {

enum class State {
    MENU, RUNNING, MESSAGE, BATTLE
};

struct Event {
    enum Type { MESSAGE, BATTLE } type;
    void * data;
};

static State state= State::RUNNING;
static Hero hero(4, 4);
static uint32_t tick= 0;
static Queue<Event, 8> eventQueue;
static Message * currentMessage;

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

    // Service the queue
    if( state == State::RUNNING ){
        if( !eventQueue.isEmpty() ){
            tracef("queue %d", eventQueue.getSize());
            Event evt = eventQueue.pop();
            tracef("evt. data %x", (int)(evt.data));
            switch( evt.type ){
                case Event::MESSAGE: {
                    currentMessage = (Message *)evt.data;
                    state = State::MESSAGE;
                    break;
                }
                case Event::BATTLE: {
                    // TODO
                    break;
                }
            }
        }
    }

    // Render everything
    map::render(hero.getX()/10, hero.getY()/10, tick);
    hero.render(tick);

    // Game state machine
    switch( state ){
        default:
        case State::RUNNING:{
            // Manage player character
            hero.update(tick);
            break;
        }
        case State::MESSAGE:{
            Str * str = currentMessage->getStr();
            // display string, todo overflow
            *DRAW_COLORS = 0x0014;
            rect(4, 46, 160-8, 64);
            *DRAW_COLORS = 0x0041;
            text(str->get(), 8, 56);
            if( currentMessage->update() ){
                // complete, resume running
                trace("resume from msg");
                state= State::RUNNING;
            }
            break;
        }
    }

    // // Debug info
    // if( (gamepad & (BUTTON_1 | BUTTON_2)) == (BUTTON_1 | BUTTON_2)){
    //     // show player position on screen:
    //     *DRAW_COLORS = 0x0041;
    //     StrBuffer<8> str;
    //     str.appendUint8((uint8_t)hero.getX());
    //     str.append(',');
    //     str.appendUint8((uint8_t)hero.getY());
    //     text(str.get(), 0, 1);
    // }
    tick ++;
}

void push(Message * message) {
    eventQueue.push({Event::MESSAGE, message});
}

void push(Battle * battle) {
    (void) battle;
}

// Deleteme
void menu_render(int tick) {
    *DRAW_COLORS = 0x0041;
    int8_t count = (int8_t)(tick / 18);
    StrBuffer<6> str;
    str.appendUint8((uint8_t)count, ' ');
    str.append('/');
    str.appendUint8((uint8_t)(count+2));

    int ox = 90;
    int oy = 2;
    text(str.get(), 0, 0);
    *DRAW_COLORS = 0x0044;
    rect(ox, oy, 68, 22);
    *DRAW_COLORS = (tick/5) % 2 == 0 ? 0x0031 : 0x0032;
    text(" Attack ", ox+2, oy+2);
    *DRAW_COLORS = 0x0041;
    text(" Gear   ", ox+2, oy+12);

    *DRAW_COLORS = 0x0004;
    hline(0, 160-9, 160); // top border of text
    *DRAW_COLORS = (tick/5) % 2 == 0 ? 0x0041 : 0x0042;
    text("WILDEWERE claws you!", 0, 160-8);
}

} // namespace gameloop
