
#pragma once

// common area for game state
// only interactive tiles are saved

namespace bboard {

void save();
int getForTile(uint8_t tx, uint8_t ty);
int getForInventory(uint8_t i);

} // namespace bboard