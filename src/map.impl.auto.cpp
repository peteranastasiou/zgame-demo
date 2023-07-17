// Auto-generated from res/map.json

#include "map.impl.auto.hpp"

#include "map.dialogue.hpp"

namespace map {

Npc bec(22, "Bec", &dialogue::becRMsg);
Npc warren(20, "Warren", &dialogue::warrenMsg);
Npc barbara(18, "Barbara", &dialogue::barbaraMsg);
Phone phone(73, "phone");
Door ashbyFrontDoor(68, "ashbyFrontDoor");
PeterParty peter(17, "Peter", &dialogue::peterBday);
Npc jacinta(38, "Jacinta", &dialogue::jacintaMsg);
Npc megF(39, "Meg F", &dialogue::megFMsg);
Npc bek(22, "Bek", &dialogue::bekMsg);
TreeGate backyardTree(54, "backyardTree");
Door pickleDoor(84, "pickleDoor");
Npc peter_(16, "Peter_", &dialogue::peterJervois);
CampFire campFire(58, "campFire");
PickleMan _pickleMan(20, "_pickleMan");
Npc peter__(16, "Peter__", &dialogue::peterWedding);
PeterProp peterPropose(62, "PeterPropose");
Door ki_exit(100, "ki_exit");
Npc anne(22, "Anne", &dialogue::anneMsg);
Npc roger(21, "Roger", &dialogue::rogerMsg);
Npc kim(96, "Kim", &dialogue::kimMsg);
Npc richard(35, "Richard", &dialogue::richardMsg);
Npc kathryn(38, "Kathryn", &dialogue::kathrynMsg);
Npc thomasandKahla(22, "Thomas and Kahla", &dialogue::thomasMsg);
Npc thomasandKahla_(21, "Thomas and Kahla_", &dialogue::thomasMsg);
Npc george(36, "George", &dialogue::georgeMsg);
Snake snake(108, "snake");
Exit exit(68, "exit");
Alfie alfie(118, "Alfie");
Npc evie(98, "Evie", &dialogue::evieMsg);
Npc sophie(97, "Sophie", &dialogue::sophieMsg);
Npc kate(18, "Kate", &dialogue::kateMsg);
Npc suthan(21, "Suthan", &dialogue::suthanMsg);
Npc ren(22, "Ren", &dialogue::renMsg);
Npc grahamandBarb(19, "Graham and Barb", &dialogue::grahamMsg);
Npc leanneandNeil(22, "Leanne and Neil", &dialogue::leanne);
Trunk trunk(94, "Trunk");

// Run-time expanded array of objects
// Not done at compile time to save ROM
// Note: Looks like BSS is copied in full at start up, so large static arrays are wasteful of ROM
Object ** OBJECTS = nullptr;

void initObjects() {
    OBJECTS = new Object*[MAP_WIDTH * MAP_HEIGHT];

    OBJECTS[5 + MAP_WIDTH*6] = &bec;
    OBJECTS[1 + MAP_WIDTH*25] = &warren;
    OBJECTS[2 + MAP_WIDTH*25] = &barbara;
    OBJECTS[7 + MAP_WIDTH*23] = &phone;
    OBJECTS[2 + MAP_WIDTH*21] = &ashbyFrontDoor;
    OBJECTS[7 + MAP_WIDTH*3] = &peter;
    OBJECTS[7 + MAP_WIDTH*5] = &jacinta;
    OBJECTS[8 + MAP_WIDTH*7] = &megF;
    OBJECTS[6 + MAP_WIDTH*2] = &bek;
    OBJECTS[9 + MAP_WIDTH*3] = &backyardTree;
    OBJECTS[17 + MAP_WIDTH*5] = &pickleDoor;
    OBJECTS[13 + MAP_WIDTH*13] = &peter_;
    OBJECTS[25 + MAP_WIDTH*15] = &campFire;
    OBJECTS[15 + MAP_WIDTH*3] = &_pickleMan;
    OBJECTS[15 + MAP_WIDTH*23] = &peter__;
    OBJECTS[22 + MAP_WIDTH*24] = &peterPropose;
    OBJECTS[25 + MAP_WIDTH*9] = &ki_exit;
    OBJECTS[22 + MAP_WIDTH*3] = &anne;
    OBJECTS[23 + MAP_WIDTH*3] = &roger;
    OBJECTS[21 + MAP_WIDTH*6] = &kim;
    OBJECTS[24 + MAP_WIDTH*6] = &richard;
    OBJECTS[27 + MAP_WIDTH*15] = &kathryn;
    OBJECTS[23 + MAP_WIDTH*15] = &thomasandKahla;
    OBJECTS[23 + MAP_WIDTH*16] = &thomasandKahla_;
    OBJECTS[27 + MAP_WIDTH*16] = &george;
    OBJECTS[20 + MAP_WIDTH*25] = &snake;
    OBJECTS[14 + MAP_WIDTH*11] = &exit;
    OBJECTS[16 + MAP_WIDTH*12] = &alfie;
    OBJECTS[13 + MAP_WIDTH*25] = &evie;
    OBJECTS[14 + MAP_WIDTH*25] = &sophie;
    OBJECTS[12 + MAP_WIDTH*25] = &kate;
    OBJECTS[16 + MAP_WIDTH*25] = &suthan;
    OBJECTS[17 + MAP_WIDTH*25] = &ren;
    OBJECTS[14 + MAP_WIDTH*27] = &grahamandBarb;
    OBJECTS[16 + MAP_WIDTH*27] = &leanneandNeil;
    OBJECTS[14 + MAP_WIDTH*22] = &trunk;
}

} // namespace map

