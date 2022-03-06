/**
 * Main
 * Peter Anastasiou 2022
 */

#include "wasm4.h"

const uint8_t smiley[] = {
    0b11000011,
    0b10000001,
    0b00100100,
    0b00100100,
    0b00000000,
    0b00100100,
    0b10011001,
    0b11000011,
};

class Player
{
private:
    int32_t x_;
    int32_t y_;
    int32_t updatePeriod_ = 1;

public:
    Player(int x, int y): x_(x), y_(y)
    {
    }

    void render()
    {
        *DRAW_COLORS = 2;
        blit(smiley, x_, y_, 8, 8, BLIT_1BPP);
    }
    
    void update(int32_t tick)
    {
        if( tick % updatePeriod_ != 0 ){ return; }
        
        uint8_t gamepad = *GAMEPAD1;
        if( gamepad & (BUTTON_LEFT | BUTTON_RIGHT) ){
            if( gamepad & BUTTON_RIGHT ){ x_++; }
            if( gamepad & BUTTON_LEFT ){ x_--; }
        }else{
            if( gamepad & BUTTON_DOWN ){ y_++; }
            if( gamepad & BUTTON_UP ){ y_--; }
        }
    }
};

Player player(70, 70);
int32_t tick;

void start()
{
    trace("hello");
    tick= 0;
}

void update () {
    *DRAW_COLORS = 2;
    text("Hello World", 10, 10);

    player.update(tick);

    player.render();
    
    tick ++;
}
