#ifndef TRACKER_H_
#define TRACKER_H_

#include <vector>

#include "interface_render.h"
#include "enum_states_of_game.h"
#include "logger.h"
#include "massage_key_not_work.h"
#include "massage_key_push.h"
#include "massage_log_lose.h"
#include "massage_log_new_game.h"
#include "massage_log_win.h"

class Tracker {
private:
    Field& field;
    Player& player;
    Interface_render& render;
    Massage_log_win* massage_win;
    Massage_log_lose* massage_lose;
    Massage_log_new_game* massage_new_game;
    Massage_key_push* massage_key_push;
    Massage_key_not_work* massage_key_not_work;

    void Make_log(std::vector <Logger*> logger, Massage* massage);

public:
    Tracker(Interface_render& Value_render, Interlayer& layer, Player& Value_player, Field& Value_field);
    void Checking_the_state(States_game state, std::vector<Logger*> logger);
    ~Tracker();
};


#endif