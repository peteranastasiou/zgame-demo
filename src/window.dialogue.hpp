
#pragma once

#include "window.hpp"
#include "wasm4.h"
#include "str.hpp"
#include "txt.hpp"
#include <string.h>


class Dialogue: public Window {
private:
    char const * msg_;
    uint8_t msgLen_;
    uint8_t numLines_;
    int16_t textY_;  // position to display text to be centred vertically
    uint8_t charIdx_; // for animation

public:
    Dialogue(char const * msg) {
        setMessage(msg);
    }

    virtual void reset() override {
        charIdx_ = 0;
    }

    void setMessage(char const * msg) {
        msg_ = msg;
        msgLen_ = (uint8_t)strlen(msg);
        charIdx_ = 0;

        // do a dry run to pre-calculate number of lines
        numLines_ = txt::reflow(msg_, 0, -1, true);
        textY_ = SCREEN_SIZE/2 - txt::TEXT_HEIGHT * numLines_ / 2;
    }

    void skipAnimation() {
        charIdx_ = msgLen_;
    }

    virtual bool update() override {
        if( gameloop::wasPressed(BUTTON_1 | BUTTON_2) ){
            if( charIdx_ < msgLen_ ){
                // skip to end of animation
                charIdx_ = msgLen_;
            }else{
                // exit
                return true;
            }
        }
        return false;
    }

    virtual void render(uint32_t tick) override {
        (void) tick;
        // display text box
        *DRAW_COLORS = 0x0014;
        rect(1, textY_ - 6, SCREEN_SIZE - 2, txt::TEXT_HEIGHT * numLines_ + 11);

        if( charIdx_ < msgLen_ ) charIdx_ ++;

        // reflow text within the box
        *DRAW_COLORS = 0x0041;
        txt::reflow(msg_, textY_, charIdx_);
    }
};
