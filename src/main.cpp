/**
 * Main
 * Peter Anastasiou 2022
 */

#include "wasm4.h"
#include "audio.hpp"
#include "player.hpp"

Tone hello[] = {
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

Tone bass[] = {
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

Tone beat[] = {
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

Player player(5, 5);
int32_t tick= 0;
uint8_t previousGamepad= 0;

void start()
{
    trace("hello");
}

void update () {
    *DRAW_COLORS = 2;
    //text("Hello World", 10, 10);

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

    AudioChannel::pulse1.tick();
    AudioChannel::pulse2.tick();
    AudioChannel::triangle.tick();
    AudioChannel::noise.tick();

    // Manage player character
    player.update(tick);
    player.render();
    
    tick ++;
}
