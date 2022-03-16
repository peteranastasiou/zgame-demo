
#include "sprites.hpp"
#include "spritesheet.hpp"
#include "wasm4.h"

namespace sprites {

void blit(int idx, int32_t x, int32_t y, uint32_t flags)
{
    uint32_t sx = 16 * ((uint32_t)idx % 9);
    uint32_t sy = 16 * ((uint32_t)idx / 9);
    blitSub(SPRITES_, x, y, 16, 16, sx, sy, 144, BLIT_2BPP | flags);
}

} // namespace sprites
