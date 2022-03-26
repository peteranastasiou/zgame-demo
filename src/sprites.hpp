#pragma once

#include <stdint.h>

namespace sprites {

// TODO remove old
uint8_t const HOOD_FWD1=45;
uint8_t const HOOD_FWD2=46;
uint8_t const HOOD_FWD3=47;
uint8_t const HOOD_SIDE1=48;
uint8_t const HOOD_SIDE2=49;
uint8_t const HOOD_SIDE3=50;
uint8_t const HOOD_BACK1=51;
uint8_t const HOOD_BACK2=52;
uint8_t const HOOD_BACK3=53;

// new
uint8_t const STONE_WALL= 22;
uint8_t const CANDELABRA_UNLIT= 23;
uint8_t const CANDELABRA_LIT1= 24;
uint8_t const CANDELABRA_LIT2= 25;
uint8_t const STONE_FLOOR= 30;

void blit(int idx, int32_t x, int32_t y, uint32_t flags);

} // namespace sprites