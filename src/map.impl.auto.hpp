
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
 52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 
 54,  54,  54,  54,  54,  54,  54,  54,  54,  54,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  66,  64,  64,  64,  64,  64,  64,  64,  64,  67, 182, 151, 152, 153, 154, 155, 156, 157, 158, 182, 
 54, 145, 145, 145, 145, 145, 145, 145, 145,  54,  52,  52,  66,  64,  64,  64,  64,  67,  52,  52,  65, 145, 145, 145, 145, 145, 145, 145, 145,  81, 150, 167, 168, 169, 170, 171, 172, 173, 174, 159, 
 54, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 180, 145, 145, 145,  76,  81,  52,  52,  65, 145, 145, 145, 145, 145,  42,  43,  44,  81, 166, 182, 182, 182, 182, 182, 182, 182, 182, 175, 
 66,  64,  48,  64,  64, 132,  64,  48,  64,  67,  52,  52,  65, 145, 145, 145,  92,  81,  52,  52,  65, 145, 145, 145, 105, 145, 145, 145, 145,  81, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 
 65, 145, 145, 145, 145, 145, 145, 145, 145,  81,  52,  52,  65,  34, 145, 145, 145, 148, 145, 145, 180, 145, 145, 145, 121, 145,  56,  70,  71,  81, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 
 49,  56,  70,  71, 145, 145, 145, 145, 145,  81,  52,  52,  65,  88, 145, 145, 145,  81,  52,  52,  65, 145, 145, 145, 145, 145,  56,  86,  87,  81, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 
 65,  56,  86,  87, 145, 145, 145, 145, 145,  81,  52,  52,  82,  80,  50,  50,  80,  83,  52,  52,  65, 145, 145, 145, 145, 145, 145,  72,  72,  81, 230, 231, 184, 184, 184, 184, 184, 184, 238, 239, 
 65,  53,  72,  72, 145, 145, 145, 145, 145,  81,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  65, 120, 145, 145, 145, 145, 145, 145, 145,  81, 246, 247, 232, 233, 234, 235, 236, 237, 254, 255, 
 82,  80,  80,  80,  80,  80,  80, 164,  80,  83,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  82,  80,  50,  50,  50, 164,  80,  50,  50,  83, 182, 182, 248, 249, 250, 251, 252, 253, 182, 182, 
 52,  52,  52,  52,  52,  52,  52, 145,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52, 145,  52,  52,  52,  52, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
145,  54, 145, 145, 145, 145,  54, 145,  54, 145,  66,  64,  64,  64,  64,  64,  64,  64,  64,  67,  54,  54, 145, 145,  54, 145,  54, 145,  54,  54, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
 14,  14,  14,  14,  14,  14,  15, 145,  13,  14,  65, 145, 145, 145, 145, 145, 145, 145, 105,  81, 145, 145,  54,  54, 145, 145, 145,  54, 145,  54, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
 57, 145, 145, 145, 145, 145, 145, 145, 145,  57,  49, 145, 145, 145, 145, 145, 145, 145, 121,  81, 145,  54, 145, 145, 145, 145, 145, 145,  54, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
 11, 129, 129, 129, 129, 129, 129, 129, 129,  11,  65,  56, 145, 145, 145, 145, 145, 145, 145,  81,  54, 145, 145, 145, 145, 145, 145, 145,  54, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
 12, 128, 128, 128, 128, 128, 128, 128, 128,  12,  65, 102, 103, 103, 104, 145, 145, 145, 106,  81,  54, 145, 145, 145, 145, 145, 145, 145, 145,  54, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
 28, 144, 144, 144, 144, 144, 144,  29,  30,  31,  65,  42,  43,  43,  43,  44, 145, 145, 122,  81, 145,  54, 145, 145, 145, 145, 145, 145,  54, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
 11, 129, 129, 129, 129, 129, 129,  45,  46,  47,  65,  25,  53,  53,  53,  24, 145, 145, 145,  81,  54, 145, 145, 145, 145, 145, 145, 145, 145,  54, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
 57, 145, 145, 145, 145, 145, 145, 145, 145,  57,  65,  41,  43,  43,  44,  40, 145, 145, 145,  81, 145,  54,  54, 145,  54, 145,  54, 145, 145,  54, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
 14,  15, 145,  13,  14,  14,  14,  14,  14,  14,  82,  80,  80,  80,  80,  80,  80, 164,  80,  83,  54, 145, 145,  54, 145,  54, 145,  54, 145,  54, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
 52,  52, 145,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52, 145,  52,  52,  52,  52,  52,  52,  52,  52,  52,  52, 145,  52, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
 66,  64, 132,  48,  64,  64,  48,  48,  64,  67,  54,  54,  54,  77,  78,  79,  54, 145,  54,  54,  53,  90,  53,  90,  53,  90,  53, 145, 145,  90, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
 65, 145, 145, 145, 145,  56,  70,  71,  55,  81,  54,  54, 145,  93,  94, 145, 145, 145, 145,  54,  90,  34,  90,  34,  90,  34,  90, 145, 145,  90, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
 65, 145, 145, 145, 145,  56,  86,  87,  55,  81,  54, 145, 145,  93, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,  89, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
 65, 145, 145, 145, 145, 145, 145, 145, 145,  81,  54,  54, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,  89,  89, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
 65, 145, 145, 145,  24,  25, 145, 145,  88,  81,  54,  54, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,  89, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
 49, 145, 145, 145,  40,  41,  42,  43,  44,  81,  54,  54, 145, 145, 145, 145, 145, 145, 145,  54,  91,  91,  91,  91,  91,  91,  91,  91,  91,  91, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
 65, 145, 145, 145, 145, 145, 145, 145, 145,  81,  54, 145, 145, 145, 145, 145, 145, 145,  54,  54, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
 65, 120, 145, 145, 145, 145, 145, 145,  89,  81,  54,  54,  54,  54, 145, 145,  54,  54,  54,  54, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
 82,  80,  80,  80,  80,  80,  80,  80,  80,  83,  54,  54,  54,  54,  54,  54,  54,  54,  54,  54, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,  34, 145, 145, 145, 145, 145, 145, 145, 145, 145, 
};

uint8_t const NUM_OBJECTS = 26;

extern Npc BecRowe;
extern Npc Warren;
extern Npc Barbara;
extern Phone phone;
extern Door ashbyFrontDoor;
extern OneTimeNpc PeterBday;
extern Npc Jacinta;
extern Npc Meg;
extern Npc Adam;
extern Npc Bec;
extern TreeGate backyardTree;
extern Door pickleDoor;
extern Npc Peterjervois;
extern CampFire campFire;
extern PickleMan pickleMan;
extern Npc Peterwedding;
extern Npc PeterPropose;
extern Door ki_exit;
extern Npc anne;
extern Npc roger;
extern Npc kim;
extern Npc richard;
extern Npc Kathryn;
extern Npc Kahla;
extern Npc Thomas;
extern Npc George;

extern Object ** OBJECTS;

void initObjects();

} // namespace map

