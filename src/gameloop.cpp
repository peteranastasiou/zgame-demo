
#include "gameloop.hpp"
#include "wasm4.h"
#include "audio.system.hpp"
#include "window.menu.hpp"
#include "config.hpp"
#include "sprites.hpp"
#include "map.hpp"
#include "str.hpp"
#include "queue.hpp"

namespace gameloop {

enum class State {
    MENU, RUNNING, WINDOW
};

Hero hero(2, 11);

static State state= State::RUNNING;
static uint32_t tick= 0;
static Queue<Window *, 8> windowQueue;
static Window * currentWindow;

// Main Menu
class MainMenu : public Menu {
public:
    MainMenu(): Menu(items_) {}

    bool selected(int idx) {
        switch( idx ){
            case 0: trace("stats"); break;
            case 1: trace("inventory"); break;
            case 2: trace("save/load"); break;
            case 3: trace("instructions"); break;
        }
        return true;
    }
private:
    static char const * const items_[];
};
char const * const MainMenu::items_[] = {
    "stats",
    "inventory",
    "save/load",
    "instructions",
    nullptr
};
static MainMenu mainMenu;

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

            // Open main menu
            if( wasPressed(BUTTON_2) ){
                pushWindow(&mainMenu);
            }
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
    tick ++;
}

void pushWindow(Window * window) {
    windowQueue.push(window);
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
