
#pragma once

#include "window.hpp"
#include "wasm4.h"
#include "str.hpp"


class Dialogue: public Window {
private:
    char const * str_;

public:
    Dialogue(char const * cstr): str_(cstr) {}

    virtual bool update() override {
        return gameloop::wasPressed(BUTTON_1 | BUTTON_2);
    }

    virtual void render(uint32_t tick) override {
        (void) tick;
        // display string, todo overflow
        *DRAW_COLORS = 0x0014;
        rect(4, 46, 160-8, 64);
        *DRAW_COLORS = 0x0041;
        text(str_, 8, 56);
    }
};
