
#include "sprites.hpp"
#include "sprites.impl.auto.hpp"
#include "wasm4.h"

namespace sprites {

void blit(int idx, int32_t x, int32_t y, uint32_t flags)
{
    uint32_t sx = 16 * ((uint32_t)idx % SPRITES_Columns);
    uint32_t sy = 16 * ((uint32_t)idx / SPRITES_Columns);
    blitSub(SPRITES_, x, y, 16, 16, sx, sy, SPRITES_Width, BLIT_2BPP | flags);
}

} // namespace sprites
