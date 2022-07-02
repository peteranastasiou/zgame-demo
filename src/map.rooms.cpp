
#include "map.rooms.hpp"
#include "config.hpp"
#include "gameloop.hpp"
#include "map.impl.auto.hpp"
#include "rand.hpp"

namespace map {

static int const NUM_ROOMS_ACROSS = MAP_WIDTH / SCREEN_WIDTH;

void ashbyUpdate(int sx, int sy, uint32_t tick) {
    (void) sx;
    (void) sy;
    (void) tick;
    // Open gate when all sconces are lit
    if( !ashbyFrontDoor.isTriggered() ){
        if( phone.isTriggered() ){
            ashbyFrontDoor.setTriggered(true);
        }
    }
}

void update(int sx, int sy, uint32_t tick) {
    // linear room number (L->R, top->bot):
    int roomIdx = sy * NUM_ROOMS_ACROSS + sx;

    switch( roomIdx ){
        case 0: return;
        case 1: return;
        case 2: return;
        case 3: return;
        case 4: return;
        case 5: return;
        case 6: return;
        case 7: return;
        case 8: ashbyUpdate(sx, sy, tick); return;
        case 9: return;
        case 10: return;
        default: return;
    }
}

char const * getRoomLabel(int sx, int sy){
    // linear room number (L->R, top->bot):
    int roomIdx = sy * NUM_ROOMS_ACROSS + sx;

    switch( roomIdx ){
        case 0: return "<0>";
        case 1: return "<1>";
        case 2: return "<2>";
        case 3: return "<3>";
        case 4: return "<4>";
        case 5: return "<5>";
        case 6: return "<6>";
        case 7: return "<7>";
        case 8: return "10 Ashby Avenue";
        case 9: return "<9>";
        case 10: return "<10>";
        default: return "???";
    }
}

} // namespace map
