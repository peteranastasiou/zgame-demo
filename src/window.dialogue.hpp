
#pragma once

#include "window.hpp"
#include "wasm4.h"
#include "str.hpp"
#include "txt.hpp"
#include <string.h>


class Dialogue: public Window {
private:
    static uint8_t const MAX_LINES_ON_PAGE = 15;
    char const * msg_;
    char const * msgPtr_;
    int16_t msgLen_;
    int16_t numLinesOnPage_;
    int16_t numCharsOnPage_;
    uint16_t textY_;  // position to display text to be centred vertically
    int16_t charIdx_; // for animation

    void setMessage(char const * msg) {
        msgPtr_ = msg;
        charIdx_ = 0;

        // do a dry run to pre-calculate number of lines on first page
        numLinesOnPage_ = txt::reflow(numCharsOnPage_, msgPtr_, 0, -1, MAX_LINES_ON_PAGE, true);
        textY_ = SCREEN_SIZE/2 - txt::TEXT_HEIGHT * (uint16_t)numLinesOnPage_ / 2;
    }

public:
    Dialogue(char const * msg) {
        msg_ = msg;
        msgLen_ = (int16_t)strlen(msg);
        setMessage(msg_);
    }

    virtual void reset() override {
        setMessage(msg_);
    }

    void skipAnimation() {
        charIdx_ = msgLen_;
    }

    virtual bool update() override {
        if( gameloop::wasPressed(BUTTON_1 | BUTTON_2) ){
            if( charIdx_ < numCharsOnPage_ ){
                // skip to end of animation
                charIdx_ = numCharsOnPage_;
            }else if( msgPtr_[charIdx_] != '\0' ){
                // skip to next page of message
                setMessage( msgPtr_ + numCharsOnPage_ );
            }else{
                // end of message, exit
                return true;
            }
        }
        return false;
    }

    virtual void render(uint32_t tick) override {
        (void) tick;
        // display text box
        *DRAW_COLORS = 0x0014;
        int32_t h = txt::TEXT_HEIGHT * numLinesOnPage_ + 11;
        rect(1, textY_ - 6, SCREEN_SIZE - 2, (uint32_t)h);

        // reflow text within the box
        *DRAW_COLORS = 0x0041;
        int16_t nChars;
        txt::reflow(nChars, msgPtr_, textY_, charIdx_, MAX_LINES_ON_PAGE);

        // unless on last page, show ... 
        if( charIdx_ < numCharsOnPage_ ){
            charIdx_ ++;
        }else if( msgPtr_[charIdx_] != '\0' ){
            text("->", SCREEN_SIZE - 20, textY_ + h - 2*txt::TEXT_HEIGHT);
        }
    }
};
