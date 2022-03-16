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

void background_render()
{
    *DRAW_COLORS = 0x4321;
    for( int i = 0; i < NUM_TILES; ++i ){
        for( int j = 0; j < NUM_TILES; ++j ){
            sprites::blit(sprites::COBBLESTONE, i*16, j*16, 0);
        }
    }
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
