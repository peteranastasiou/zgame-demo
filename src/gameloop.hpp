
#pragma once

#include "str.hpp"
#include "hero.hpp"
#include "window.hpp"
#include "map.hpp"

namespace gameloop {

// TODO work out where this lives
extern Hero hero;

// one tick of the game
void update();

// Push a window to display it next
void pushWindow(Window * message);

// enqueue an object to trigger next
void pushObjectToTrigger(map::Object * object);

// Input
bool wasPressed(uint8_t btn);
bool isPressed(uint8_t btn);

}

