/**
 * Main
 * Peter Anastasiou 2022
 */

#include "wasm4.h"
#include "audio.hpp"
#include "player.hpp"
#include "config.hpp"
#include "sprites.hpp"

static Tone const hello[] = {
    {Note::C4, 5, 10},
    {Note::NONE, 5, 10},
    {Note::E4, 10, 10},
    {Note::F4, 5, 10},
    {Note::NONE, 10, 10},
    {Note::A5, 10, 10},
    {Note::D5, 10, 10},
    {Note::C5, 10, 10},
    {Note::NONE, 10, 10},
    {Note::END, 0, 0},
};

static Tone const bass[] = {
    {Note::C2, 10, 10},
    {Note::D2, 10, 10},
    {Note::E2, 10, 10},
    {Note::F2, 10, 10},
    {Note::C2, 10, 10},
    {Note::A3, 10, 10},
    {Note::D3, 10, 10},
    {Note::C3, 10, 10},
    {Note::END, 0, 0},
};

static Tone const beat[] = {
    {Note::C6, 1, 10},
    {Note::C4, 2, 10},
    {Note::NONE, 1, 10},
    {Note::C4, 2, 10},
    {Note::C6, 1, 10},
    {Note::C4, 2, 10},
    {Note::NONE, 1, 10},
    {Note::C4, 2, 10},
    {Note::LOOP, 0, 0},
};

static uint8_t const stone[64] = {
    0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x03,0xff,0xff,0xfc,0xfc,0xff,0xf0,0xfc,0xa8,0xff,0xcf,0x3f,0xab,0xff,0xfa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0f,0xfc,0x0f,0xfc,0xf3,0xf3,0xf3,0xff,0xaf,0xf2,0xa3,0xff,0xff,0xfe,0xaf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
};

static Player player(5, 5);
static int32_t tick= 0;
static uint8_t previousGamepad= 0;

void start()
{
    trace("hello");
}

// string class


void dec99toStr(char *& buf, int8_t n)
{
    if( n < 0 ){
        *buf++= '-';
        n *= -1;
    }
    if( n > 99 ) n = 99; // max number supported
    if( n < 10 ){
        *buf++= '0'+n;
    }else{
        *buf++= '0'+(n/10);
        *buf++= '0'+(n%10);
    }
}

void background_render()
{
    *DRAW_COLORS = 0x4321;
    for( int i = 0; i < NUM_TILES; ++i ){
        for( int j = 0; j < NUM_TILES; ++j ){
            sprites::blit(64, i*16, j*16, 0);
        }
    }
    *DRAW_COLORS = 0x0041;
    int8_t count = (int8_t)(tick / 18);
    char buf[6];
    char * bufPtr = buf;
    dec99toStr(bufPtr, count);
    *bufPtr++='/';
    dec99toStr(bufPtr, count);
    *bufPtr++=0;

    int ox = 90;
    int oy = 2;
    text(buf, 0, 0);
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

void update () {
    // Manage Audio
    uint8_t gamepad = *GAMEPAD1;
    uint8_t pressedThisFrame = gamepad & (gamepad ^ previousGamepad);    
    previousGamepad = gamepad;
    if( pressedThisFrame & BUTTON_1 ){
        AudioChannel::pulse1.play(hello);
        AudioChannel::triangle.setVolume(75);
        AudioChannel::triangle.play(bass);
        AudioChannel::noise.play(beat);
    }

    // Update audio channels
    AudioChannel::pulse1.tick();
    AudioChannel::pulse2.tick();
    AudioChannel::triangle.tick();
    AudioChannel::noise.tick();

    // Manage player character
    player.update(tick);

    // Render everything
    background_render();
    player.render(tick);

    tick ++;
}
