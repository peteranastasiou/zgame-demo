
#pragma once

#include "str.hpp"


class Message {
public:
    // true means message has finished
    virtual bool update()=0;

    virtual Str * getStr()=0;
};

class Battle {
// TODO interface
};

namespace gameloop {

// one tick of the game
void update();

// Push to event loop
void push(Message * message);
void push(Battle * battle);

// Input
bool wasPressed(uint8_t btn);
bool isPressed(uint8_t btn);

}

