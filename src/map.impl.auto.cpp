// Auto-generated from res/map.json

#include "map.impl.auto.hpp"

#include "map.dialogue.hpp"

namespace map {

Npc becR(43, "Bec Rowe", &dialogue::becRMsg);
Npc testMan(45, "TestNPC", &dialogue::test);

// Run-time expanded array of objects
// Not done at compile time to save ROM
// Note: Looks like BSS is copied in full at start up, so large static arrays are wasteful of ROM
Object ** OBJECTS = nullptr;

void initObjects() {
    OBJECTS = new Object*[MAP_WIDTH * MAP_HEIGHT];

    OBJECTS[3 + MAP_WIDTH*3] = &becR;
    OBJECTS[4 + MAP_WIDTH*3] = &testMan;
}

} // namespace map

