// Auto-generated from res/map.json

#include "map.impl.auto.hpp"

#include "map.dialogue.hpp"

namespace map {

Npc BecRowe(22, "BecRowe", &dialogue::becRMsg);
Npc Warren(20, "Warren", &dialogue::test);
Npc Barbara(18, "Barbara", &dialogue::test);
Phone phone(73, "phone");
Door ashbyFrontDoor(68, "ashbyFrontDoor");
OneTimeNpc PeterBday(17, "PeterBday", &dialogue::test);
Npc Jacinta(38, "Jacinta", &dialogue::test);
Npc Meg(39, "Meg", &dialogue::test);
Npc Adam(19, "Adam", &dialogue::test);
Npc Bec(22, "Bec", &dialogue::test);
TreeGate backyardTree(54, "backyardTree");
Door pickleDoor(84, "pickleDoor");
Npc Peterjervois(16, "Peterjervois", &dialogue::test);
CampFire campFire(58, "campFire");
PickleMan pickleMan(20, "pickleMan");
Npc Peterwedding(16, "Peterwedding", &dialogue::test);
Npc PeterPropose(62, "PeterPropose", &dialogue::test);
Door ki_exit(100, "ki_exit");
Npc anne(22, "anne", &dialogue::test);
Npc roger(21, "roger", &dialogue::test);
Npc kim(96, "kim", &dialogue::test);
Npc richard(35, "richard", &dialogue::test);

// Run-time expanded array of objects
// Not done at compile time to save ROM
// Note: Looks like BSS is copied in full at start up, so large static arrays are wasteful of ROM
Object ** OBJECTS = nullptr;

void initObjects() {
    OBJECTS = new Object*[MAP_WIDTH * MAP_HEIGHT];

    OBJECTS[2 + MAP_WIDTH*2] = &BecRowe;
    OBJECTS[1 + MAP_WIDTH*25] = &Warren;
    OBJECTS[2 + MAP_WIDTH*25] = &Barbara;
    OBJECTS[7 + MAP_WIDTH*23] = &phone;
    OBJECTS[2 + MAP_WIDTH*21] = &ashbyFrontDoor;
    OBJECTS[8 + MAP_WIDTH*3] = &PeterBday;
    OBJECTS[8 + MAP_WIDTH*6] = &Jacinta;
    OBJECTS[8 + MAP_WIDTH*7] = &Meg;
    OBJECTS[6 + MAP_WIDTH*2] = &Adam;
    OBJECTS[7 + MAP_WIDTH*2] = &Bec;
    OBJECTS[9 + MAP_WIDTH*3] = &backyardTree;
    OBJECTS[17 + MAP_WIDTH*5] = &pickleDoor;
    OBJECTS[12 + MAP_WIDTH*13] = &Peterjervois;
    OBJECTS[25 + MAP_WIDTH*15] = &campFire;
    OBJECTS[15 + MAP_WIDTH*3] = &pickleMan;
    OBJECTS[13 + MAP_WIDTH*23] = &Peterwedding;
    OBJECTS[21 + MAP_WIDTH*24] = &PeterPropose;
    OBJECTS[25 + MAP_WIDTH*9] = &ki_exit;
    OBJECTS[22 + MAP_WIDTH*3] = &anne;
    OBJECTS[23 + MAP_WIDTH*3] = &roger;
    OBJECTS[21 + MAP_WIDTH*6] = &kim;
    OBJECTS[24 + MAP_WIDTH*6] = &richard;
}

} // namespace map

