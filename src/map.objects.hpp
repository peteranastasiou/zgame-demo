
#pragma once

#include "map.hpp"
#include "sprites.hpp"
#include "gameloop.hpp"
#include "window.dialogue.hpp"
#include "window.menu.hpp"
#include "inventory.hpp"

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
    Npc(uint8_t sprite, char const * name, Dialogue * dialogue): 
        title_(name) {
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
        // underscore supresses name
        if( name_[0] != '_' ) gameloop::pushWindow(&title_);
        gameloop::pushWindow(dialogue_);
        triggered_= true;
    }

private:
    uint8_t sprite_;
    char const * name_;
    Dialogue * dialogue_;
    Dialogue title_;
};

class PeterParty : public Object {
public:
    PeterParty(uint8_t sprite, char const * name, Dialogue * dialogue): 
        title_(name) {
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

    virtual void interact() override;
private:
    uint8_t sprite_;
    char const * name_;
    Dialogue * dialogue_;
    Dialogue title_;
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
        (void) cycle;
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
        if(triggered_) render_(sprite_ + (cycle/2) % 2, x, y, 0);
    }

    virtual char const * getLabel() override {
        return "Sea snake";
    }

    virtual void interact() override {
    }

private:
    uint8_t sprite_;
};

class Alfie : public Object {
public:
    Alfie(uint8_t sprite, char const * name){
        sprite_ = sprite;
        (void) name;
    }

    virtual bool passable() override { return false; }

    virtual void render(int cycle, int x, int y) override {
        *DRAW_COLORS = 0x0234;
        render_(sprite_ + (cycle/2) % 2, x, y, 0);
    }

    virtual char const * getLabel() override {
        return "Alfie";
    }

    virtual void interact() override;

private:
    uint8_t sprite_;
};

class Trunk : public Object {
public:
    Trunk(uint8_t sprite, char const * name){
        sprite_ = sprite;
        (void) name;
    }

    virtual bool passable() override { return false; }

    virtual void render(int cycle, int x, int y) override {
        (void) cycle;
        *DRAW_COLORS = 0x0234;
        render_(sprite_, x, y, 0);
    }

    virtual char const * getLabel() override {
        return "Trunk";
    }

    virtual void interact() override;

private:
    uint8_t sprite_;
};

class Exit : public Object {
public:
    Exit(uint8_t sprite, char const * name){
        sprite_ = sprite;
        (void) name;
    }

    virtual bool passable() override { return false; }

    virtual void render(int cycle, int x, int y) override {
        (void)cycle;
        *DRAW_COLORS = 0x0234;
        render_(sprite_, x, y, 0);
    }

    virtual char const * getLabel() override {
        return "Exit";
    }

    virtual void interact() override;

private:
    uint8_t sprite_;
};

class Pickle : public Object {
public:
    Pickle(uint8_t sprite, char const * name){
        sprite_ = sprite;
        (void) name;
    }

    virtual bool passable() override { return false; }

    virtual void render(int cycle, int x, int y) override {
        (void)cycle;
        *DRAW_COLORS = 0x0234;
        render_(sprite_, x, y, 0);
    }

    virtual char const * getLabel() override {
        return "";
    }

    virtual void interact() override;

private:
    uint8_t sprite_;
};

class Lamby : public Object {
public:
    Lamby(uint8_t sprite, char const * name){
        sprite_ = sprite;
        (void) name;
    }

    virtual bool passable() override { return false; }

    virtual void render(int cycle, int x, int y) override {
        (void)cycle;
        *DRAW_COLORS = 0x0234;
        render_(sprite_, x, y, 0);
    }

    virtual char const * getLabel() override {
        return "";
    }

    virtual void interact() override;
private:
    uint8_t sprite_;
};


class BatWing : public Object {
public:
    BatWing(uint8_t sprite, char const * name){
        sprite_ = sprite;
        (void) name;
    }

    virtual bool passable() override { return triggered_; }

    virtual void render(int cycle, int x, int y) override {
        (void)cycle;
        *DRAW_COLORS = 0x0234;
        if(!triggered_) render_(sprite_, x, y, 0);
    }

    virtual char const * getLabel() override {
        return "";
    }

    virtual void interact() override;
private:
    uint8_t sprite_;
};

class Charades : public Object {
public:
    Charades(uint8_t sprite, char const * name){
        sprite_ = sprite;
        (void) name;
    }

    virtual bool passable() override { return false; }

    virtual void render(int cycle, int x, int y) override {
        (void)cycle;
        *DRAW_COLORS = 0x0234;
        render_(sprite_, x, y, 0);
    }

    virtual char const * getLabel() override {
        return "";
    }

    virtual void interact() override;
private:
    uint8_t sprite_;
};


class Tent : public Object {
public:
    Tent(uint8_t sprite, char const * name){
        sprite_ = sprite;
        (void) name;
    }

    virtual bool passable() override { return false; }

    virtual void render(int cycle, int x, int y) override {
        (void)cycle;
        *DRAW_COLORS = 0x0234;
        render_(sprite_, x, y, 0);
    }

    virtual char const * getLabel() override {
        return "";
    }

    virtual void interact() override;
private:
    uint8_t sprite_;
};

class Catan : public Object {
public:
    Catan(uint8_t sprite, char const * name){
        sprite_ = sprite;
        (void) name;
    }

    virtual bool passable() override { return false; }

    virtual void render(int cycle, int x, int y) override {
        (void)cycle;
        *DRAW_COLORS = 0x0234;
        render_(sprite_, x, y, 0);
    }

    virtual char const * getLabel() override {
        return "";
    }

    virtual void interact() override;
private:
    uint8_t sprite_;
};

class Portal : public Object {
public:
    Portal(uint8_t sprite, char const * name){
        sprite_ = sprite;
        (void) name;
    }

    virtual bool passable() override { return inventory::love; }

    virtual void render(int cycle, int x, int y) override {
        (void)cycle;
        *DRAW_COLORS = 0x0234;
        render_(sprite_, x, y, 0);
    }

    virtual char const * getLabel() override {
        return "";
    }

    virtual void interact() override {};
private:
    uint8_t sprite_;
};

class Cereal : public Object {
public:
    Cereal(uint8_t sprite, char const * name){
        sprite_ = sprite;
        (void) name;
    }

    virtual bool passable() override { return false; }

    virtual void render(int cycle, int x, int y) override {
        (void)cycle;
        *DRAW_COLORS = 0x0234;
        render_(sprite_, x, y, 0);
    }

    virtual char const * getLabel() override {
        return "";
    }

    virtual void interact() override;
private:
    uint8_t sprite_;
};

class Self : public Object {
public:
    Self(uint8_t sprite, char const * name){
        sprite_ = sprite;
        (void) name;
    }

    virtual bool passable() override { return false; }

    virtual void render(int cycle, int x, int y) override {
        (void)cycle;
        (void) x;
        (void) y;
    }

    virtual char const * getLabel() override {
        return "";
    }

    virtual void interact() override;
private:
    uint8_t sprite_;
};

} // namespace map
