#pragma once

#include <stdint.h>

/** 
 * Basic LCG random number generator
 * updates seed in place and also returns it for convenience
 */
extern uint32_t rand(uint32_t & seed);
