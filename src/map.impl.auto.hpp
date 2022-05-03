
#pragma once

// Auto-generated from res/map.json

#include <stdint.h>
#include "map.objects.hpp"

namespace map {
uint8_t const MAP_WIDTH = 40;
uint8_t const MAP_HEIGHT = 30;
uint8_t const SCREEN_WIDTH = 10;
uint8_t const SCREEN_HEIGHT = 10;

uint8_t const TILES[] = {
 22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  41,  41,  41,  41,  41,  41,  41,  41,  22,  22,  22,  22,  22, 
 22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  41,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  41,  41,  41,  41,  41,  41,  22,  22,  22,  41,  22,  22,  22,  22,  41,  41,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  41,  41,  41,  41,  41,  41,  41,  41,  41,  41,  41,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  41,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  41,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  41,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  78,  55,  69,  56,  55,  56,  65,  69,  69,  56,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  30,  30,  30,  30,  30,  30,  30,  30,  22,  22,  30,  30,  30,  30,  30,  30,  30,  30,  22,  79,  79,  55,  68,  79,  65,  69,  69,  69,  68,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  30,  22,  22,  22,  22,  22,  22,  30,  30,  30,  30,  30,  30,  30,  30,  30,  30,  30,  22,  79,  79,  75,  79,  79,  55,  69,  69,  69,  68,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  30,  30,  30,  30,  30,  30,  30,  30,  22,  22,  22,  22,  22,  22,  22,  22,  22,  30,  22,  79,  79,  59,  79,  79,  79,  76,  69,  56,  79,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  22,  30,  22,  30,  22,  22,  30,  22,  22,  22,  30,  30,  30,  30,  30,  30,  30,  30,  22,  79,  79,  78,  79,  79,  65,  69,  56,  65,  68,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  30,  30,  22,  30,  30,  22,  30,  30,  22,  22,  30,  30,  22,  30,  30,  30,  30,  30,  22,  79,  79,  79,  79,  65,  56,  59,  79,  55,  66,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  30,  30,  22,  22,  22,  22,  30,  22,  22,  22,  30,  30,  22,  30,  30,  30,  30,  30,  30,  68,  58,  66,  65,  69,  67,  69,  66,  65,  56,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  30,  30,  30,  30,  30,  30,  30,  30,  22,  22,  30,  30,  22,  22,  22,  22,  22,  22,  22,  65,  68,  55,  69,  77,  55,  69,  69,  56,  75,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  30,  22,  22,  30,  30,  22,  22,  30,  22,  22,  30,  30,  30,  30,  30,  30,  30,  30,  22,  69,  67,  67,  69,  69,  66,  55,  56,  58,  56,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  30,  22,  22,  76,  69,  69,  69,  69,  69,  66,  65,  66,  79,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 
 22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  20,  20,  20,  20,  20,  20,  20,  62,  20,  20,  36,  36,  36,  36,  36,  36,  36,  36,  36,  42,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36, 
 22,  30,  30,  30,  30,  30,  30,  30,  30,  36,  36,  41,  52,  53,  53,  53,  53,  74,  33,  36,  41,  36,  41,  41,  36,  36,  36,  41,  36,  42,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36, 
 22,  30,  30,  30,  30,  30,  30,  30,  15,  36,  36,  41,  62,  41,  41,  41,  33,  33,  52,  53,  41,  41,  41,  36,  41,  41,  36,  41,  41,  42,  36,  36,  36,  41,  41,  41,  41,  42,  36,  36, 
 22,  30,  30,  30,  30,  30,  30,  30,  30,  30,  73,  73,  60,  53,  53,  53,  53,  53,  61,  36,  36,  41,  41,  41,  41,  41,  36,  36,  41,  36,  36,  36,  36,  41,  36,  36,  36,  41,  36,  36, 
 22,  30,  30,  30,  47,  13,  30,  30,  15,  36,  36,  41,  41,  41,  41,  41,  41,  41,  62,  36,  36,  42,  36,  41,  42,  36,  36,  36,  41,  36,  36,  36,  36,  41,  36,  36,  36,  41,  36,  36, 
 22,  30,  30,  30,  13,  47,  30,  30,  30,  36,  36,  41,  41,  41,  41,  41,  41,  41,  62,  36,  36,  42,  36,  36,  36,  42,  36,  41,  42,  41,  41,  41,  41,  41,  36,  36,  36,  36,  36,  36, 
 22,  30,  30,  30,  30,  30,  30,  30,  30,  36,  36,  41,  41,  41,  41,  41,  41,  41,  62,  36,  36,  42,  42,  36,  41,  41,  41,  41,  36,  36,  36,  36,  36,  41,  36,  36,  36,  36,  36,  36, 
 22,  30,  30,  30,  30,  30,  30,  30,  30,  36,  36,  41,  41,  41,  41,  41,  41,  41,  62,  36,  36,  42,  42,  36,  41,  41,  36,  41,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36, 
 22,  30,  30,  30,  30,  30,  30,  30,  30,  36,  36,  36,  36,  41,  41,  41,  41,  41,  62,  36,  36,  36,  42,  42,  42,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36, 
 22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36,  36, 
};

uint8_t const NUM_OBJECTS = 32;

Sconce sconce_17_13;
Sconce sconce_13_15;
Sconce sconce_11_10;
MushroomsPickup mushroomspickup_11_26;
MushroomsPickup mushroomspickup_12_26;
MushroomsPickup mushroomspickup_13_26;
MushroomsPickup mushroomspickup_14_26;
MushroomsPickup mushroomspickup_15_26;
MushroomsPickup mushroomspickup_15_27;
MushroomsPickup mushroomspickup_14_27;
MushroomsPickup mushroomspickup_13_27;
MushroomsPickup mushroomspickup_12_27;
MushroomsPickup mushroomspickup_11_27;
MushroomsPickup mushroomspickup_12_25;
MushroomsPickup mushroomspickup_11_25;
MushroomsPickup mushroomspickup_13_25;
MushroomsPickup mushroomspickup_14_25;
MushroomsPickup mushroomspickup_15_25;
MushroomsPickup mushroomspickup_15_24;
MushroomsPickup mushroomspickup_13_24;
MushroomsPickup mushroomspickup_14_24;
MushroomsPickup mushroomspickup_11_24;
MushroomsPickup mushroomspickup_12_24;
Knight knight_10_23;
Sconce sconce_1_10;
Sconce sconce_8_10;
Sconce sconce_1_19;
Sconce sconce_8_19;
Hut hut_5_15;
Egg egg_18_28;
Jukebox jukebox_5_18;
Gate gate_9_12;

// Run-time expanded array of objects
// Not done at compile time to save ROM
// Note: Looks like BSS is copied in full at start up, so large static arrays are wasteful of ROM
Object ** OBJECTS = nullptr;

void initObjects() {
    OBJECTS = new Object*[MAP_WIDTH * MAP_HEIGHT];

    OBJECTS[17 + MAP_WIDTH*13] = &sconce_17_13;
    OBJECTS[13 + MAP_WIDTH*15] = &sconce_13_15;
    OBJECTS[11 + MAP_WIDTH*10] = &sconce_11_10;
    OBJECTS[11 + MAP_WIDTH*26] = &mushroomspickup_11_26;
    OBJECTS[12 + MAP_WIDTH*26] = &mushroomspickup_12_26;
    OBJECTS[13 + MAP_WIDTH*26] = &mushroomspickup_13_26;
    OBJECTS[14 + MAP_WIDTH*26] = &mushroomspickup_14_26;
    OBJECTS[15 + MAP_WIDTH*26] = &mushroomspickup_15_26;
    OBJECTS[15 + MAP_WIDTH*27] = &mushroomspickup_15_27;
    OBJECTS[14 + MAP_WIDTH*27] = &mushroomspickup_14_27;
    OBJECTS[13 + MAP_WIDTH*27] = &mushroomspickup_13_27;
    OBJECTS[12 + MAP_WIDTH*27] = &mushroomspickup_12_27;
    OBJECTS[11 + MAP_WIDTH*27] = &mushroomspickup_11_27;
    OBJECTS[12 + MAP_WIDTH*25] = &mushroomspickup_12_25;
    OBJECTS[11 + MAP_WIDTH*25] = &mushroomspickup_11_25;
    OBJECTS[13 + MAP_WIDTH*25] = &mushroomspickup_13_25;
    OBJECTS[14 + MAP_WIDTH*25] = &mushroomspickup_14_25;
    OBJECTS[15 + MAP_WIDTH*25] = &mushroomspickup_15_25;
    OBJECTS[15 + MAP_WIDTH*24] = &mushroomspickup_15_24;
    OBJECTS[13 + MAP_WIDTH*24] = &mushroomspickup_13_24;
    OBJECTS[14 + MAP_WIDTH*24] = &mushroomspickup_14_24;
    OBJECTS[11 + MAP_WIDTH*24] = &mushroomspickup_11_24;
    OBJECTS[12 + MAP_WIDTH*24] = &mushroomspickup_12_24;
    OBJECTS[10 + MAP_WIDTH*23] = &knight_10_23;
    OBJECTS[1 + MAP_WIDTH*10] = &sconce_1_10;
    OBJECTS[8 + MAP_WIDTH*10] = &sconce_8_10;
    OBJECTS[1 + MAP_WIDTH*19] = &sconce_1_19;
    OBJECTS[8 + MAP_WIDTH*19] = &sconce_8_19;
    OBJECTS[5 + MAP_WIDTH*15] = &hut_5_15;
    OBJECTS[18 + MAP_WIDTH*28] = &egg_18_28;
    OBJECTS[5 + MAP_WIDTH*18] = &jukebox_5_18;
    OBJECTS[9 + MAP_WIDTH*12] = &gate_9_12;
}

} // namespace map

