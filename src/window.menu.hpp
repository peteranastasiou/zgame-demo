
#pragma once

#include "window.hpp"
#include "gameloop.hpp"
#include "wasm4.h"
#include "txt.hpp"

class Menu : public Window {
public:
    Menu(char const * const * items): items_(items) {
        // count items:
        numItems_= 0;
        for( int i= 0; items_[i] != nullptr; ++i ){
            numItems_++;
        }
        textY_ = SCREEN_SIZE/2 - txt::TEXT_HEIGHT * numItems_ / 2;
        selectedIdx_ = 0;
    }

    virtual void reset() override {
        selectedIdx_ = 0;
    }

    virtual bool update() override {
        // cancel button
        if( gameloop::wasPressed(BUTTON_2) ){
            return true;
        }
        // check if item is selected
        if( gameloop::wasPressed(BUTTON_1) ){
            if( selected(selectedIdx_) ){
                // impl indicates we should exit now:
                return true;
            }
        }
        bool up = gameloop::wasPressed(BUTTON_UP);
        bool down = gameloop::wasPressed(BUTTON_DOWN);
        if( up && !down ){
            if( selectedIdx_ > 0 ) selectedIdx_--;
            else selectedIdx_ = numItems_-1;
        }
        if( down && !up ){
            if( selectedIdx_ < numItems_-1 ) selectedIdx_++;
            else selectedIdx_ = 0;
        }
        return false;
    }

    virtual void render(uint32_t tick) override {
        tick /= 4; // slow down animation
        
        // display text box
        *DRAW_COLORS = 0x0014;
        rect(5, textY_ - 6, SCREEN_SIZE - 10, txt::TEXT_HEIGHT * numItems_ + 13);

        // text options
        for( int i= 0; i < numItems_; ++i ){
            int y = textY_ + i*(txt::TEXT_HEIGHT + 1);
            if( i==selectedIdx_ ){
                *DRAW_COLORS = 0x0033;
                rect(10, y - 1, SCREEN_SIZE - 20, txt::TEXT_HEIGHT);

                *DRAW_COLORS = tick % 2 ? 0x0031 : 0x0034;
            }else{
                *DRAW_COLORS = 0x0041;
            }
            text(items_[i], 18, y);
        }
    }

    // Implement to define functionality on selection:
    // return true means to close the window
    virtual bool selected(int idx)= 0;

private:
    uint8_t selectedIdx_;
    uint8_t numItems_;
    uint8_t textY_;
    char const * const * items_;
};

