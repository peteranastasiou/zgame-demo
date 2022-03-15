
#include "player.hpp"
#include "config.hpp"
#include "wasm4.h"


uint8_t const smiley_[] = {
    0b11000011,
    0b10000001,
    0b00100100,
    0b00100100,
    0b00000000,
    0b00100100,
    0b10011001,
    0b11000011,
};

Player::Player(int x, int y): gx_(x), gy_(y)
{
    state_= State::IDLE;
    px_ = gx_ * TILE_SIZE;
    py_ = gy_ * TILE_SIZE;
}

void Player::render()
{
    *DRAW_COLORS = 2;
    blit(smiley_, px_, py_, 8, 8, BLIT_1BPP);
}

void Player::update(int32_t tick)
{
    if( tick % updatePeriod_ != 0 ) return;

    switch( state_ ){
        case State::IDLE:
            idle_();
            break;

        case State::WALKING:
            walk_();
            break;
    }
}

void Player::idle_()
{
    // accept new direction
    uint8_t gamepad = *GAMEPAD1;
    
    // consider movement which would counteract, together, so e.g. pressing L & R does nothing:
    uint8_t const LR = BUTTON_RIGHT | BUTTON_LEFT;
    uint8_t const UD = BUTTON_UP | BUTTON_DOWN;

    if( (gamepad & LR) == BUTTON_RIGHT && move_(gx_+1, gy_)) return; 
    if( (gamepad & LR) == BUTTON_LEFT  && move_(gx_-1, gy_)) return;
    if( (gamepad & UD) == BUTTON_DOWN  && move_(gx_, gy_+1)) return;
    if( (gamepad & UD) == BUTTON_UP    && move_(gx_, gy_-1)) return;
}

bool Player::move_(int nx, int ny)
{
    // TODO test position nx, ny is okay to move into or else interact with
    gx_ = nx;
    gy_ = ny;
    state_= State::WALKING;
    return true;
}

void Player::walk_()
{
    // set point to walk towards
    int32_t sx = gx_*TILE_SIZE;
    int32_t sy = gy_*TILE_SIZE;

    // walking animation
    if( px_ < sx )      px_ ++;
    else if( px_ > sx ) px_ --;
    else if( py_ < sy ) py_ ++;
    else if( py_ > sy ) py_ --;
    else{
        // we are done walking
        state_= State::IDLE;
    }
}
