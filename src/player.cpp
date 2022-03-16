
#include "player.hpp"
#include "config.hpp"
#include "sprites.hpp"
#include "wasm4.h"


Player::Player(int x, int y): gx_(x), gy_(y)
{
    px_ = gx_ * TILE_SIZE;
    py_ = gy_ * TILE_SIZE;
    dir_= S;
    walking_= false;
    step_= 0;
    frame_= 0;
}

void Player::render(int32_t tick)
{
    (void) tick;
    int sprite;
    uint8_t flags = 0;
    switch( dir_ ){
        case N:
            sprite= sprites::HOOD_BACK1;
            break;
        case S:
            sprite= sprites::HOOD_FWD1;
            break;
        case E:
            sprite= sprites::HOOD_SIDE1;
            break;
        case W:
            sprite= sprites::HOOD_SIDE1;
            flags |= BLIT_FLIP_X;
            break;
    }
    *DRAW_COLORS = 0x4320; // note: bg color of sprite is made transparent
    sprites::blit(sprite + frame_, px_, py_, flags);
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
        if( gamepad == BUTTON_RIGHT ){ dir_= E; move_(gx_+1, gy_); }
        if( gamepad == BUTTON_LEFT  ){ dir_= W; move_(gx_-1, gy_); }
        if( gamepad == BUTTON_DOWN  ){ dir_= S; move_(gx_, gy_+1); }
        if( gamepad == BUTTON_UP    ){ dir_= N; move_(gx_, gy_-1); }
    }
    // update set point post movement:
    sx = gx_*TILE_SIZE;
    sy = gy_*TILE_SIZE;

    // walking animation
    walking_= true;
    if( px_ < sx )      px_ ++;
    else if( px_ > sx ) px_ --;
    else if( py_ < sy ) py_ ++;
    else if( py_ > sy ) py_ --;
    else walking_= false;

    // manage animation steps
    if( walking_ ){
        if( step_++ % animationPeriod_ == 0 && ++frame_ > 2) frame_= 1;
    }else{
        step_= 0;
        frame_= 0;
    }
}

bool Player::move_(int nx, int ny)
{
    // TODO test position nx, ny is okay to move into or else interact with
    gx_ = nx;
    gy_ = ny;
    return true;
}
