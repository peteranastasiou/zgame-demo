
#pragma once

#include <stdint.h>

namespace txt {

uint8_t const TEXT_HEIGHT = 9;

/**
 * Draw text box with reflowed text
 */
uint8_t reflow(char const * msg, int y, int len=-1, bool dryRun=false);

}
