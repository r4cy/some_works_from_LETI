#ifndef TRACKER_H_
#define TRACKER_H_

#include "interface_render.h"
#include "enum_states_of_game.h"

class Tracker {
private:
    Field& field;
    Player& player;
    Interface_render& render;

public:
    Tracker(Interface_render& Value_render, Player& Value_player, Field& Value_field);
    void Checking_the_state(States_game state) const;
};


#endif