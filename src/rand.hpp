#pragma once

#include <stdint.h>

/** 
 * Basic LCG random number generator
 * updates seed in place and also returns it for convenience
 */
extern uint32_t rand(uint32_t & seed);

/**
 * roll <n>d<sides> e.g. 2d6
 */
extern uint32_t roll(uint32_t & seed, uint32_t n, uint32_t sides);

