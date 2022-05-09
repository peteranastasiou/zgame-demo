
#include "rand.hpp"

uint32_t rand(uint32_t & seed) {
    // Factors from Borland C rand impl
    seed = (22695477 * seed + 1);
    return seed;
}

uint32_t roll(uint32_t & seed, uint32_t n, uint32_t sides) {
    uint32_t sum= 0;
    for( uint32_t i = 0; i < n; ++i ){
        uint32_t r = rand(seed);
        uint32_t d = r % sides + 1;
        sum += d;
    }
    return sum;
}
