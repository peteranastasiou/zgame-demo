
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

    // set point to walk towards
    int32_t sx = gx_*TILE_SIZE;
    int32_t sy = gy_*TILE_SIZE;

    // if idle:
    if( px_ == sx && py_ == sy ){
        // accept new direction to move:
        uint8_t gamepad = *GAMEPAD1;

        // mask the d pad so that pressing multiple keys stops movement
        gamepad &= BUTTON_RIGHT | BUTTON_LEFT | BUTTON_UP | BUTTON_DOWN;
        if( gamepad == BUTTON_RIGHT ) move_(gx_+1, gy_);
        if( gamepad == BUTTON_LEFT  ) move_(gx_-1, gy_);
        if( gamepad == BUTTON_DOWN  ) move_(gx_, gy_+1);
        if( gamepad == BUTTON_UP    ) move_(gx_, gy_-1);
    }
    // update set point post movement:
    sx = gx_*TILE_SIZE;
    sy = gy_*TILE_SIZE;

    // walking animation
    if( px_ < sx )      px_ ++;
    else if( px_ > sx ) px_ --;
    else if( py_ < sy ) py_ ++;
    else if( py_ > sy ) py_ --;
}

bool Player::move_(int nx, int ny)
{
    // TODO test position nx, ny is okay to move into or else interact with
    gx_ = nx;
    gy_ = ny;
    return true;
}
