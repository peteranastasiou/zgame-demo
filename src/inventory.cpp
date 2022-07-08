#include "inventory.hpp"
#include "window.menu.hpp"


namespace inventory {
bool lamby = false;
bool invite = false;
bool date = false;
bool pickle = false;
bool batWing = false;
bool ring = false;
bool photo = false;
bool love = false;
bool charades = false;
bool catan = false;
bool tent = false;

char const * unknown = "???";

class InvMenu : public Menu {
public:
    InvMenu() {}
    virtual char const * getTitle() override {
        return "ITEMS:";
    }
    //Guess how many pickles in the pickle jar?
    virtual char const * getLabel(int idx) override {
        switch( idx ){
            case 0: return lamby ? "Lamby" : unknown;
            case 1: return invite ? "Invitation" : unknown;
            case 2: return date ? "Date" : unknown;
            case 3: return pickle ? "Pickle" : unknown;
            case 4: return charades ? "Charades prompt" : unknown;
            case 5: return tent ? "Tent Peg" : unknown;
            case 6: return batWing ? "Bat Wing" : unknown;
            case 7: return ring ? "Ring" : unknown;
            case 8: return photo ? "Photo" : unknown;
            case 9: return catan ? "Catan" : unknown;
            case 10: return love ? "Love" : unknown;
            default: return nullptr;
        }
    }

    virtual bool selected(int idx) override {
        (void) idx;
        return true;
    }
};
static InvMenu invMenu;

void show() {
    gameloop::pushWindow(&invMenu);
}
};
