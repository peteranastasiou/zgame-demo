
#include "map.hpp"
#include "config.hpp"
#include "gameloop.hpp"
#include "map.impl.auto.hpp"
#include "rand.hpp"

namespace map {

/**
 * Room specific game logic happens here
 */
void update(int sx, int sy, uint32_t tick);

/**
 * Get label of room at screen coords sx, sy
 */
char const * getRoomLabel(int sx, int sy);

} // namespace map
