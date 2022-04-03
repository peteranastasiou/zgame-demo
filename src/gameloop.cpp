#include "gameloop.hpp"
#include "wasm4.h"
#include "audio.system.hpp"
#include "hero.hpp"
#include "config.hpp"
#include "sprites.hpp"
#include "map.hpp"
#include "str.hpp"

namespace gameloop {

static Hero hero(7, 2);
static uint32_t tick= 0;
static uint8_t previousGamepad= 0;

enum class State {
    MENU, RUNNING, MESSAGE, BATTLE
} state;

void update(){
    // Manage Audio
    uint8_t gamepad = *GAMEPAD1;
    uint8_t pressedThisFrame = gamepad & (gamepad ^ previousGamepad);    
    previousGamepad = gamepad;
    if( pressedThisFrame & BUTTON_1 ){
        audio::demo();
    }

    // Manage player character
    hero.update(tick);

    // Render everything
    map::render(hero.getX()/10, hero.getY()/10, tick);
    hero.render(tick);

    // show player position on screen:
    *DRAW_COLORS = 0x1231;
    Str<8> str;
    str.appendUint8((uint8_t)hero.getX());
    str.append(',');
    str.appendUint8((uint8_t)hero.getY());
    text(str.get(), 0, 1);

    tick ++;
}

void pushEvent(Event evt){
    (void) evt;
    // TODO
}
    
void menu_render(int tick)
{
    *DRAW_COLORS = 0x0041;
    int8_t count = (int8_t)(tick / 18);
    Str<6> str;
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
