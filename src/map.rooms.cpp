
#include "map.rooms.hpp"
#include "config.hpp"
#include "gameloop.hpp"
#include "map.impl.auto.hpp"
#include "rand.hpp"

namespace map {

static int const NUM_ROOMS_ACROSS = MAP_WIDTH / SCREEN_WIDTH;

static void triggerOn(Object * o1, Object * o2) {
    if( o1->isTriggered() && !o2->isTriggered() ){
        // do once!
        gameloop::pushObjectToTrigger(o2);
    }
}

static void usaUpdate() {
    triggerOn(&_pickleMan, &pickleDoor);
}

static void ashbyUpdate() {
    triggerOn(&phone, &ashbyFrontDoor);
}

static void thomasBdayUpdate() {
    triggerOn(&peter, &backyardTree);
}

static void kiUpdate() {
    // TODO
}

static void beachUpdate() {
    triggerOn(&peterPropose, &snake);
}

void update(int sx, int sy, uint32_t tick) {
    (void) tick;
    // linear room number (L->R, top->bot):
    int roomIdx = sy * NUM_ROOMS_ACROSS + sx;

    switch( roomIdx ){
        case 0: thomasBdayUpdate(); return;
        case 1: usaUpdate(); return;
        case 2: kiUpdate(); return;
        case 3: return;
        case 4: return;
        case 5: return;
        case 6: return;
        case 7: return;
        case 8: ashbyUpdate(); return;
        case 9: return;
        case 10: beachUpdate(); return;
        default: return;
    }
}

char const * getRoomLabel(int sx, int sy){
    // linear room number (L->R, top->bot):
    int roomIdx = sy * NUM_ROOMS_ACROSS + sx;

    //                 "--------------------"
    switch( roomIdx ){
        case 0: return "   Thomas' Party";
        case 1: return "Sandwich store, USA";
        case 2: return "  Kangaroo Island";
        case 3: return "-";
        case 4: return "     Blackwood";
        case 5: return "  Home Sweet Home";
        case 6: return "      Camping";
        case 7: return "-";
        case 8: return "  10 Ashby Avenue";
        case 9: return "   Burbrook Forest";
        case 10: return "   Amedee Island";
        default: return "???";
    }
}

} // namespace map
