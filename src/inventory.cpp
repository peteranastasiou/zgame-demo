#include "inventory.hpp"
#include "window.menu.hpp"
#include "window.dialogue.hpp"
#include "str.hpp"


namespace inventory {
bool lamby = false;
bool invite = false;
bool cereal = false;
bool date = false;
bool pickle = false;
bool batWing = false;
bool ring = false;
bool photo = false;
bool love = false;
bool charades = false;
bool catan = false;
bool tent = false;
bool self = false;

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
            case 2: return cereal ? "Cereal Bowl" : unknown;
            case 3: return date ? "Date" : unknown;
            case 4: return pickle ? "Pickle" : unknown;
            case 5: return charades ? "Charades prompt" : unknown;
            case 6: return tent ? "Tent Peg" : unknown;
            case 7: return batWing ? "Bat Wing" : unknown;
            case 8: return ring ? "Ring" : unknown;
            case 9: return photo ? "Photo" : unknown;
            case 10: return catan ? "Catan" : unknown;
            case 11: return love ? "Love" : unknown;
            case 12: return self ? "Self" : unknown;
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

class ScoreDialogue : public Dialogue {
public:
    ScoreDialogue() : Dialogue("") {
    }

    virtual void reset() override {
        uint8_t score = (uint8_t)lamby + (uint8_t) invite + (uint8_t) cereal +
        (uint8_t) date + (uint8_t) pickle + (uint8_t) charades + (uint8_t) tent +
        (uint8_t) batWing + (uint8_t) ring + (uint8_t) photo + (uint8_t) catan + (uint8_t) love + (uint8_t) self;

        buf.clear();
        buf.append("Score: ");
        buf.appendUint8((uint8_t)(200.0f*score/12.0f));
        buf.append("\n");
        buf.appendUint8(score);
        buf.append(" of 12 Items");
        if( score >= 12 ){
            buf.append("\n   COMPLETE!");
        }
        setMessage(buf.get());
    }

private:
    StrBuffer<48> buf;
};

static ScoreDialogue scoreWindow;

void showScore() {
    gameloop::pushWindow(&scoreWindow);
}

};
