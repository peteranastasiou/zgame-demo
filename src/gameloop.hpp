#pragma once


namespace gameloop {

struct Event {
    enum Type { MESSAGE, BATTLE } type;
    void * data;
};

void update();

void pushEvent(Event evt);

}

