#ifndef TRACKER_H_
#define TRACKER_H_

#include <vector>

#include "interface_render.h"
#include "enum_states_of_game.h"
#include "logger.h"
#include "message_key_not_work.h"
#include "message_key_push.h"
#include "message_log_lose.h"
#include "message_log_new_game.h"
#include "message_log_win.h"

class Tracker {
private:
    Field& field;
    Player& player;
    Interface_render& render;
    Message_log_win* message_win;
    Message_log_lose* message_lose;
    Message_log_new_game* message_new_game;
    Message_key_push* message_key_push;
    Message_key_not_work* message_key_not_work;

    void Make_log(std::vector <Logger*> logger, Message* message);

public:
    Tracker(Interface_render& Value_render, Interlayer& layer, Player& Value_player, Field& Value_field);
    void Checking_the_state(States_game state, std::vector<Logger*> logger);
    ~Tracker();
};


#endif