
#include "map.hpp"
#include "config.hpp"
#include "gameloop.hpp"
#include "map.impl.auto.hpp"
#include "rand.hpp"

namespace map {

void room6Update(int sx, int sy, uint32_t tick) {
    (void) tick;

    *DRAW_COLORS = 0x0234;

    // grab current sprite of the hero and paste it all over the map
    uint8_t flags;
    int sprite = gameloop::hero.getSprite(flags);
    int px = gameloop::hero.getPX();
    int py = gameloop::hero.getPY();
    int offsetx = px % TILE_SIZE;
    int offsety = py % TILE_SIZE;
    int posx = px - sx * SCREEN_SIZE;
    int posy = py - sy * SCREEN_SIZE;
    uint32_t rand_seed = 0;
    for( int x = 0; x < SCREEN_WIDTH; x++ ){
        for( int y = 0; y < SCREEN_HEIGHT; y++ ){
            // don't draw where hero already is
            if( posx/TILE_SIZE == x && posy/TILE_SIZE == y ) continue;

            uint8_t f = flags;
            int s = sprite;
            uint32_t r = rand(rand_seed);
            if( r % 3 == 0 ) f |= BLIT_FLIP_Y;
            if( r % 2 == 0 ){
                // re-arrange sprites if facing up/down
                // (awful lazy hack dependant on sprite order):
                if( s < 3 ) s += 6;
                else if( s > 5 ) s -= 6;
                else f ^= BLIT_FLIP_X;  // facing left/right
            }
            sprites::blit(s, TILE_SIZE * x + offsetx, TILE_SIZE * y + offsety, f);

            // TODO wall around edge
            // if( x==0 || y==0 || x==SCREEN_WIDTH-1 || y==SCREEN_HEIGHT-1 ){
            //     // partially cover with wall overlay
            //     sprites::blit(sprites::STONE_WALL, TILE_SIZE * x, TILE_SIZE * y);
            // }
        }
    }
}

void update(int sx, int sy, uint32_t tick) {
    static int const NUM_ROOMS_ACROSS = MAP_WIDTH / SCREEN_WIDTH;

    // linear room number (L->R, top->bot):
    int roomIdx = sy * NUM_ROOMS_ACROSS + sx;

    switch( roomIdx ){
        case 0: return;
        case 1: return;
        case 2: return;
        case 3: return;
        case 4: return;
        case 5: return;
        case 6: room6Update(sx, sy, tick); return;
        case 7: return;
        case 8: return;
        case 9: return;
        case 10: return;
        default: return;
    }
}

} // namespace map
