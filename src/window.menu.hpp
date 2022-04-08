
#pragma once

#include "window.hpp"

class Menu : public Window {
public:
    Menu(char ** items, int numItems):
            items_(items), numItems_(numItems) {
    }

    virtual bool update() override {
        // TODO
        return false;
    }

    virtual void render(uint32_t tick) override {
        // TODO
        (void) tick;
    }

    // Implement to define functionality on selection:
    virtual void selected(int selection)= 0;

private:
    char ** items_;
    int numItems_;
};

