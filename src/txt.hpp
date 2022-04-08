
#pragma once

#include <stdint.h>

namespace txt {

int const TEXT_HEIGHT = 9;

/**
 * Draw text box with reflowed text
 */
uint8_t reflow(char const * msg, int y, bool dryRun=false);

}