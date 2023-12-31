#ifndef TERMINAL_RENDER_H
#define TERMINAL_RENDER_H

#include <typeinfo>
#include <iostream>

#include "mine.h"
#include "teleport.h"
#include "first_aid_kit.h"
#include "interface_render.h"

class Terminal_render: public Interface_render{
public:
    void Print_playing_field(Player& player, Field& field) const override;
    void Print_player(Player& player) const override;
    void Print_start() const override;
    void Print_logger() const override;
    void Print_choose_logger() const override;
    void Print_level() const override;
    void Print_win() const override;
    void Print_lose() const override;
    void Print_game() const override;
    void Print_new_game() const override;
    void Print_the_end() const override;
    void Clear() const override;
};


#endif
