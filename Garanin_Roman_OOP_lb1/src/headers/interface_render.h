#ifndef INTERFACE_RENDER_H_
#define INTERFACE_RENDER_H_

#include "playing_field.h"
#include "player.h"

class Interface_render {
public:
    virtual void Print_playing_field(Player& player, Field& field) const = 0;
    virtual void Print_player(Player& player) const = 0;
    virtual void Print_start() const = 0;
    virtual void Print_logger() const = 0;
    virtual void Print_choose_logger() const = 0;
    virtual void Print_level() const = 0;
    virtual void Print_win() const = 0;
    virtual void Print_lose() const = 0;
    virtual void Print_game() const = 0;
    virtual void Print_new_game() const = 0;
    virtual void Print_the_end() const = 0;
    virtual void Clear() const = 0;
};


#endif
