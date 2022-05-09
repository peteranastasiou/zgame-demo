
#pragma once

#include "window.hpp"
#include "gameloop.hpp"
#include "wasm4.h"
#include "str.hpp"
#include "txt.hpp"

/**
 * DynamicDialogue is similar to Dialogue but can be overloaded to
 * provide runtime content
 */
class DynamicDialogue: public Window {
private:
    uint8_t numLines_;
    int16_t textY_;  // position to display text to be centred vertically

public:
    DynamicDialogue(uint8_t numLines): numLines_(numLines) {
        textY_ = SCREEN_SIZE/2 - txt::TEXT_HEIGHT * numLines_ / 2;
    }

    virtual void reset() override {
    }

    virtual bool update() override {
        return gameloop::wasPressed(BUTTON_1 | BUTTON_2);
    }

    // implement to provide content
    virtual char const * getMsg() = 0;

    virtual void render(uint32_t tick) override {
        (void) tick;
        // display text box
        *DRAW_COLORS = 0x0014;
        rect(1, textY_ - 6, SCREEN_SIZE - 2, txt::TEXT_HEIGHT * numLines_ + 11);

        // reflow text within the box
        *DRAW_COLORS = 0x0041;
        char const * msg = getMsg();
        txt::reflow(msg, textY_);
    }
};
