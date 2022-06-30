// Auto-generated from res/map.json

#include "map.impl.auto.hpp"

#include "map.dialogue.hpp"

namespace map {

Npc becR(22, "becR", &dialogue::becRMsg);
Npc testMan(20, "testMan", &dialogue::test);

// Run-time expanded array of objects
// Not done at compile time to save ROM
// Note: Looks like BSS is copied in full at start up, so large static arrays are wasteful of ROM
Object ** OBJECTS = nullptr;

void initObjects() {
    OBJECTS = new Object*[MAP_WIDTH * MAP_HEIGHT];

    OBJECTS[2 + MAP_WIDTH*3] = &becR;
    OBJECTS[5 + MAP_WIDTH*3] = &testMan;
}

} // namespace map

