#pragma once

#include <stdint.h>

namespace sprites {

uint8_t const HOOD_FWD1=45;
uint8_t const HOOD_FWD2=46;
uint8_t const HOOD_FWD3=47;
uint8_t const HOOD_SIDE1=48;
uint8_t const HOOD_SIDE2=49;
uint8_t const HOOD_SIDE3=50;
uint8_t const HOOD_BACK1=51;
uint8_t const HOOD_BACK2=52;
uint8_t const HOOD_BACK3=53;
uint8_t const COBBLESTONE= 63;

void blit(int idx, int32_t x, int32_t y, uint32_t flags);

} // namespace sprites