/**
 * Main
 * Peter Anastasiou 2022
 */

#include "map.hpp"
#include "audio.channel.hpp"
#include "gameloop.hpp"

void start() {
    map::init();
}

void update() {
    // Update audio channels
    audio::Channel::pulse1.tick();
    audio::Channel::pulse2.tick();
    audio::Channel::triangle.tick();
    audio::Channel::noise.tick();

    // Update game state
    gameloop::update();
}
