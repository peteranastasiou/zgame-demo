
#pragma once

#include <stdint.h>
#include "wasm4.h"

class Window {
public:
    // true means window is closing
    virtual bool update()=0;

    virtual void render(uint32_t tick)=0;

};
