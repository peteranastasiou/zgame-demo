
#include "rand.hpp"

uint32_t rand(uint32_t & seed){
    // Factors from Borland C rand impl
    seed = (22695477 * seed + 1);
    return seed;
}
