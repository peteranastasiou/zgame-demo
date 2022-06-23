/**
 * Main
 * Peter Anastasiou 2022
 */

#include "map.hpp"
#include "gameloop.hpp"

void start() {
    map::init();
}

void update() {
    // Update game state
    gameloop::update();
}


/**
 * TODO:
 * - dialogue pagenation
 * - object constructor arguments from tiled
 * - first argument of constructor autopopulated from sprite
 * - Npc construction with dialogue
 */