
#pragma once

#include "map.hpp"
#include "sprites.hpp"
#include "gameloop.hpp"
#include "window.dialogue.hpp"
#include "window.menu.hpp"

namespace map {

// ------------------------------------------------------------------
// Custom objects for the game
// ------------------------------------------------------------------

class Door : public Object {
public:
    Door(uint8_t sprite, char const * name);
    virtual bool passable() override;
    virtual void interact() override;
    virtual void render(int cycle, int x, int y) override;
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

class Phone : public Object {
public:
    Phone(uint8_t sprite, char const * name){
        sprite_ = sprite;
        name_= name;
    }

    virtual bool passable() override { return false; }

    virtual void render(int cycle, int x, int y) override;

    virtual void interact() override;

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


class PickleMan : public Object {
public:
    PickleMan(uint8_t sprite, char const * name){
        sprite_ = sprite;
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

    virtual void interact() override;

private:
    uint8_t sprite_;
    char const * name_;
};

class CampFire : public Object {
public:
    CampFire(uint8_t sprite, char const * name){
        sprite_ = sprite;
        name_ = name;
    }

    virtual bool passable() override { return false; }

    virtual void render(int cycle, int x, int y) override {
        *DRAW_COLORS = 0x0234;
        render_(sprite_ + cycle % 3, x, y, 0);
    }

    virtual char const * getLabel() override {
        return name_;
    }

    virtual void interact() override {
    }

private:
    uint8_t sprite_;
    char const * name_;
};

class PeterProp : public Object {
public:
    PeterProp(uint8_t sprite, char const * name){
        sprite_ = sprite;
        (void) name;
    }

    virtual bool passable() override { return false; }

    virtual void render(int cycle, int x, int y) override {
        *DRAW_COLORS = 0x0234;
        render_(sprite_ + (int)triggered_, x, y, 0);
    }

    virtual char const * getLabel() override {
        return "Peter";
    }

    virtual void interact() override;

private:
    uint8_t sprite_;
};

class Snake : public Object {
public:
    Snake(uint8_t sprite, char const * name){
        sprite_ = sprite;
        (void) name;
    }

    virtual bool passable() override { return false; }

    virtual void render(int cycle, int x, int y) override {
        *DRAW_COLORS = 0x0234;
        if(triggered_) render_(sprite_ + cycle % 2, x, y, 0);
    }

    virtual char const * getLabel() override {
        return "Sea snake";
    }

    virtual void interact() {
    }

private:
    uint8_t sprite_;
};
}

} // namespace map
