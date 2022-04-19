
#include "hero.hpp"
#include "config.hpp"
#include "map.hpp"
#include "sprites.hpp"
#include "wasm4.h"


Hero::Hero(int x, int y): gxCurr_(x), gyCurr_(y), gxNext_(x), gyNext_(y)
{
    px_ = gxCurr_ * TILE_SIZE;
    py_ = gyCurr_ * TILE_SIZE;
    dir_= Dir::S;
    walking_= false;
    step_= 0;
    frame_= 0;
}

void Hero::render(uint32_t tick)
{
    (void) tick;
    int sprite;
    uint8_t flags = 0;
    switch( dir_ ){
        case Dir::N:
            sprite= sprites::HOOD_BACK1;
            break;
        case Dir::S:
            sprite= sprites::HOOD_FWD1;
            break;
        case Dir::E:
            sprite= sprites::HOOD_SIDE1;
            break;
        case Dir::W:
            sprite= sprites::HOOD_SIDE1;
            flags |= BLIT_FLIP_X;
            break;
    }
    *DRAW_COLORS = 0x0234; // note: bg color of sprite is made transparent

    // get which screen we are on
    int sx = gxCurr_ / 10;
    int sy = gyCurr_ / 10;

    // position on screen to draw
    int posx = px_ - sx * SCREEN_SIZE;
    int posy = py_ - sy * SCREEN_SIZE;

    // convert global pixel to local screen pixel
    sprites::blit(sprite + frame_, posx, posy, flags);
}

void Hero::update(uint32_t tick)
{
    if( tick % updatePeriod_ != 0 ) return;

    // set point to walk towards
    int32_t sx = gxNext_*TILE_SIZE;
    int32_t sy = gyNext_*TILE_SIZE;

    // if idle:
    if( px_ == sx && py_ == sy ){
        // update last position
        gxCurr_ = gxNext_;
        gyCurr_ = gyNext_;

        // accept new direction to move:
        uint8_t gamepad = *GAMEPAD1;

        // mask the d pad so that pressing multiple keys stops movement
        gamepad &= BUTTON_RIGHT | BUTTON_LEFT | BUTTON_UP | BUTTON_DOWN;
        if( gamepad == BUTTON_RIGHT ){ dir_= Dir::E; move_(gxCurr_+1, gyCurr_); }
        if( gamepad == BUTTON_LEFT  ){ dir_= Dir::W; move_(gxCurr_-1, gyCurr_); }
        if( gamepad == BUTTON_DOWN  ){ dir_= Dir::S; move_(gxCurr_, gyCurr_+1); }
        if( gamepad == BUTTON_UP    ){ dir_= Dir::N; move_(gxCurr_, gyCurr_-1); }
    }
    // update set point post movement:
    sx = gxNext_*TILE_SIZE;
    sy = gyNext_*TILE_SIZE;

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

void Hero::move_(int nx, int ny)
{
    // interact with new tile
    bool passable = map::interact(nx, ny, dir_);

    if( passable ){
        gxNext_ = nx;
        gyNext_ = ny;
    }
}
