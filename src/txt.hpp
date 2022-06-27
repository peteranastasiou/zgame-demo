
#pragma once

#include <stdint.h>

namespace txt {

uint8_t const TEXT_HEIGHT = 9;

/**
 * Draw text box with reflowed text
 */
int16_t reflow(int16_t &numChars, char const * msg, int y, int maxLen, int maxLines, bool dryRun=false);

}
