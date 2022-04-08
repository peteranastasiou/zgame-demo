
#pragma once

#include "window.hpp"
#include "wasm4.h"
#include "str.hpp"
#include "txt.hpp"


class Dialogue: public Window {
private:
    char const * msg_;
    uint8_t numLines_;
    int16_t textY_;  // position to display text to be centred vertically

public:
    Dialogue(char const * msg): msg_(msg) {
        // do a dry run to pre-calculate number of lines
        numLines_ = txt::reflow(msg_, 0, true);
        textY_ = SCREEN_SIZE/2 - txt::TEXT_HEIGHT * numLines_ / 2;
    }

    virtual bool update() override {
        return gameloop::wasPressed(BUTTON_1 | BUTTON_2);
    }

    virtual void render(uint32_t tick) override {
        (void) tick;
        // display text box
        *DRAW_COLORS = 0x0014;
        rect(1, textY_ - 6, SCREEN_SIZE - 2, txt::TEXT_HEIGHT * numLines_ + 11);

        // reflow text within the box
        *DRAW_COLORS = 0x0041;
        txt::reflow(msg_, textY_);
    }
};
