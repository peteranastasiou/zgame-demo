// Auto-generated from res/map.json

#include "map.impl.auto.hpp"

#include "map.dialogue.hpp"

namespace map {

Npc becRowe(22, "Bec Rowe", &dialogue::becRMsg);
Npc warren(20, "Warren", &dialogue::warrenMsg);
Npc barbara(18, "Barbara", &dialogue::barbaraMsg);
Phone phone(73, "phone");
Door ashbyFrontDoor(68, "ashbyFrontDoor");
OneTimeNpc peterBday(17, "Peter Bday", &dialogue::test);
Npc jacinta(38, "Jacinta", &dialogue::test);
Npc megF(39, "Meg F", &dialogue::megFMsg);
Npc adamL(19, "Adam L", &dialogue::test);
Npc becL(22, "Bec L", &dialogue::test);
TreeGate backyardTree(54, "backyardTree");
Door pickleDoor(84, "pickleDoor");
Npc peterjervois(16, "Peter jervois", &dialogue::test);
CampFire campFire(58, "campFire");
PickleMan pickleMan(20, "pickleMan");
Npc peterwedding(16, "Peter wedding", &dialogue::test);
PeterProp peterPropose(62, "PeterPropose");
Door ki_exit(100, "ki_exit");
Npc anne(22, "anne", &dialogue::anneMsg);
Npc roger(21, "roger", &dialogue::rogerMsg);
Npc kim(96, "kim", &dialogue::test);
Npc richard(35, "richard", &dialogue::richardMsg);
Npc kathryn(38, "Kathryn", &dialogue::kathrynMsg);
Npc kahla(22, "Kahla", &dialogue::test);
Npc thomas(21, "Thomas", &dialogue::thomasMsg);
Npc george(36, "George", &dialogue::test);
Snake snake(108, "snake");

// Run-time expanded array of objects
// Not done at compile time to save ROM
// Note: Looks like BSS is copied in full at start up, so large static arrays are wasteful of ROM
Object ** OBJECTS = nullptr;

void initObjects() {
    OBJECTS = new Object*[MAP_WIDTH * MAP_HEIGHT];

    OBJECTS[2 + MAP_WIDTH*2] = &becRowe;
    OBJECTS[1 + MAP_WIDTH*25] = &warren;
    OBJECTS[2 + MAP_WIDTH*25] = &barbara;
    OBJECTS[7 + MAP_WIDTH*23] = &phone;
    OBJECTS[2 + MAP_WIDTH*21] = &ashbyFrontDoor;
    OBJECTS[8 + MAP_WIDTH*3] = &peterBday;
    OBJECTS[8 + MAP_WIDTH*6] = &jacinta;
    OBJECTS[8 + MAP_WIDTH*7] = &megF;
    OBJECTS[6 + MAP_WIDTH*2] = &adamL;
    OBJECTS[7 + MAP_WIDTH*2] = &becL;
    OBJECTS[9 + MAP_WIDTH*3] = &backyardTree;
    OBJECTS[17 + MAP_WIDTH*5] = &pickleDoor;
    OBJECTS[12 + MAP_WIDTH*13] = &peterjervois;
    OBJECTS[25 + MAP_WIDTH*15] = &campFire;
    OBJECTS[15 + MAP_WIDTH*3] = &pickleMan;
    OBJECTS[13 + MAP_WIDTH*23] = &peterwedding;
    OBJECTS[22 + MAP_WIDTH*24] = &peterPropose;
    OBJECTS[25 + MAP_WIDTH*9] = &ki_exit;
    OBJECTS[22 + MAP_WIDTH*3] = &anne;
    OBJECTS[23 + MAP_WIDTH*3] = &roger;
    OBJECTS[21 + MAP_WIDTH*6] = &kim;
    OBJECTS[24 + MAP_WIDTH*6] = &richard;
    OBJECTS[27 + MAP_WIDTH*15] = &kathryn;
    OBJECTS[23 + MAP_WIDTH*14] = &kahla;
    OBJECTS[22 + MAP_WIDTH*15] = &thomas;
    OBJECTS[27 + MAP_WIDTH*16] = &george;
    OBJECTS[20 + MAP_WIDTH*25] = &snake;
}

} // namespace map

