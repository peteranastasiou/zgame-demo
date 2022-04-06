
#pragma once

#include "str.hpp"
#include "window.hpp"

namespace gameloop {

// one tick of the game
void update();

// Push a window to display it next
void pushWindow(Window * message);

// Input
bool wasPressed(uint8_t btn);
bool isPressed(uint8_t btn);

}

