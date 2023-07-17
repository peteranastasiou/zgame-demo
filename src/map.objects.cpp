
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

static Dialogue phoneMsg1("     ITEM GET!\n    *Invitation");
static Dialogue phoneMsg2("You are invited to Thomas' 21st Birthday Party!");
void Phone::render(int cycle, int x, int y) {
    *DRAW_COLORS = 0x0234;
    uint8_t sprite = triggered_ ? sprite_ : sprite_ + (cycle % 3);
    render_(sprite, x, y, 0);
}

void Phone::interact() {
    if( !triggered_) gameloop::pushWindow(&phoneMsg1);
    gameloop::pushWindow(&phoneMsg2);

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

static Dialogue peterPropMsg1("Zoe, will you marry me?");
static Dialogue peterPropMsg2("     ITEM GET!\n       *Ring");
void PeterProp::interact() {
    if( !triggered_ ){
        gameloop::pushWindow(&peterPropMsg1);
        gameloop::pushWindow(&peterPropMsg2);
        gameloop::pushObjectToTrigger(this); // trigger self after displaying message
    }
}

static Dialogue peterItemMsg("     ITEM GET!\n       *Item");
void PeterParty::interact() {
    if( !triggered_ ){
        gameloop::pushWindow(&title_);
        gameloop::pushWindow(dialogue_);
        gameloop::pushWindow(&peterItemMsg);
        gameloop::pushObjectToTrigger(this); // trigger self after displaying message
    }
}

static Dialogue alfieMsg("Alfie");
static Dialogue alfieMsg1("Woof!\nHappy Birthday!\nI love you mum!");
static Dialogue alfieMsg2("     ITEM GET!\n*Unconditional Love");
void Alfie::interact() {
    if( !triggered_ ){
        gameloop::pushWindow(&alfieMsg);
        gameloop::pushWindow(&alfieMsg1);
        gameloop::pushWindow(&alfieMsg2);
    }
}

static Dialogue exitMsg1("THE END?");
static Dialogue exitMsg2("SCORE: 9999999\nMade with love by Peter!");
static Dialogue exitMsg3("Happy Birthday :)");
void Exit::interact() {
    gameloop::pushWindow(&exitMsg1);
    gameloop::pushWindow(&exitMsg2);
    gameloop::pushWindow(&exitMsg3);
}

} // namespace map
