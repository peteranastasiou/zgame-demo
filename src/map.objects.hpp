
#pragma once

#include "map.hpp"
#include "sprites.hpp"
#include "gameloop.hpp"
#include "window.dialogue.hpp"

namespace map {

// ------------------------------------------------------------------
// Custom objects for the game
// ------------------------------------------------------------------

static Dialogue doorMsg("You can't leave yet!");
class Door : public Object {
public:
    Door(uint8_t sprite, char const * name){
        sprite_ = sprite;
        name_= name;
    }
    virtual bool passable() override { return triggered_; }

    virtual void interact() override {
        if( !triggered_ ) gameloop::pushWindow(&doorMsg);
    }

    virtual void render(int cycle, int x, int y) override {
        (void) cycle;
        if( triggered_ ) return;
        *DRAW_COLORS = 0x1234;
        render_(sprite_, x, y, 0);
    }
private:
    uint8_t sprite_;
    char const * name_;
};

class TreeGate : public Object {
public:
    TreeGate(uint8_t sprite, char const * name){
        sprite_ = sprite;
        name_= name;
    }
    virtual bool passable() override { return triggered_; }

    virtual void interact() override { }

    virtual void render(int cycle, int x, int y) override {
        (void) cycle;
        if( triggered_ ) return;
        *DRAW_COLORS = 0x1234;
        render_(sprite_, x, y, 0);
    }
private:
    uint8_t sprite_;
    char const * name_;
};

static Dialogue phoneMsg("You are invited to Thomas' 21st Birthday Party!");
class Phone : public Object {
public:
    Phone(uint8_t sprite, char const * name){
        sprite_ = sprite;
        name_= name;
    }

    virtual bool passable() override { return false; }

    virtual void render(int cycle, int x, int y) override {
        *DRAW_COLORS = 0x0234;
        uint8_t sprite = triggered_ ? sprite_ : sprite_ + (cycle % 3);
        render_(sprite, x, y, 0);
    }

    virtual void interact() override {
        gameloop::pushWindow(&phoneMsg);

        triggered_= true;
    }

private:
    uint8_t sprite_;
    char const * name_;
};

class Npc : public Object {
public:
    Npc(uint8_t sprite, char const * name, Dialogue * dialogue){
        sprite_ = sprite;
        dialogue_ = dialogue;
        name_ = name;
    }

    virtual bool passable() override { return false; }

    virtual void render(int cycle, int x, int y) override {
        (void) cycle;
        *DRAW_COLORS = 0x0234;
        render_(sprite_, x, y, 0);
    }

    virtual char const * getLabel() override {
        return name_;
    }

    virtual void interact() override {
        gameloop::pushWindow(dialogue_);
        triggered_= true;
    }

private:
    uint8_t sprite_;
    char const * name_;
    Dialogue * dialogue_;
};

class OneTimeNpc : public Object {
public:
    OneTimeNpc(uint8_t sprite, char const * name, Dialogue * dialogue){
        sprite_ = sprite;
        dialogue_ = dialogue;
        name_ = name;
    }

    virtual bool passable() override { return triggered_; }

    virtual void render(int cycle, int x, int y) override {
        (void) cycle;
        if( triggered_ ) return; // invisible after first chat
        *DRAW_COLORS = 0x0234;
        render_(sprite_, x, y, 0);
    }

    virtual char const * getLabel() override {
        return name_;
    }

    virtual void interact() override {
        if( !triggered_ ){
            gameloop::pushWindow(dialogue_);
            gameloop::pushObjectToTrigger(this); // trigger self after displaying message
        }
    }

private:
    uint8_t sprite_;
    char const * name_;
    Dialogue * dialogue_;
};

} // namespace map
