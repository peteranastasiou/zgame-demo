#pragma once

// include auto-coded sprite indices
#include "sprites.defs.auto.hpp"

#include <stdint.h>

namespace sprites {

/**
 * @param idx   sprite index
 * @param x     pixel coordinate
 * @param y     pixel coordinate
 * @param flags wasm blit flags, not including 2BPP
 */
void blit(int idx, int32_t x, int32_t y, uint32_t flags = 0);

} // namespace sprites
