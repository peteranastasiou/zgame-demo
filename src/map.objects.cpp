
#include "map.objects.hpp"

namespace map {

// Door

Door::Door(uint8_t sprite, char const * name){
    sprite_ = sprite;
    name_= name;
}

bool Door::passable() { return triggered_; }

static Dialogue doorMsg("You can't leave yet!");

void Door::interact() {
    if( !triggered_ ) gameloop::pushWindow(&doorMsg);
}

void Door::render(int cycle, int x, int y) {
    (void) cycle;
    if( triggered_ ) return;
    *DRAW_COLORS = 0x1234;
    render_(sprite_, x, y, 0);
}

// Phone

static Dialogue phoneMsg("You are invited to Thomas' 21st Birthday Party!");
void Phone::render(int cycle, int x, int y) {
    *DRAW_COLORS = 0x0234;
    uint8_t sprite = triggered_ ? sprite_ : sprite_ + (cycle % 3);
    render_(sprite, x, y, 0);
}

void Phone::interact() {
    gameloop::pushWindow(&phoneMsg);

    triggered_= true;
}

// Pickle Man

static Dialogue pickleMsg("Guess how many pickles in the pickle jar!");
static Dialogue correctMsg("That's correct!");
class PickleMenu : public Menu {
public:
    PickleMenu() {}
    //Guess how many pickles in the pickle jar?
    virtual char const * getLabel(int idx) override {
        switch( idx ){
            case 0: return "93";
            case 1: return "127";
            case 2: return "253";
            case 3: return "278";
            case 4: return "302";
            default: return nullptr;
        }
    }

    virtual bool selected(int idx) override {
        (void) idx;
        return true;
    }
} pickleMenu;

void PickleMan::interact() {
    if( !triggered_ ){
        gameloop::pushWindow(&pickleMsg);
        gameloop::pushWindow(&pickleMenu);
        gameloop::pushWindow(&correctMsg);
        gameloop::pushObjectToTrigger(this); // trigger self after displaying message
    }
}

} // namespace map
