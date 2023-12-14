#include <cstdlib>
#include <iostream>
#include "headers/tracker.h"

Tracker::Tracker(Interface_render& Value_render, Interlayer& layer, Player& Value_player, Field& Value_field) : render(Value_render), player(Value_player), field(Value_field) {
    massage_win = new Massage_log_win(player);
    massage_lose = new Massage_log_lose(player);
    massage_new_game = new Massage_log_new_game(field);
    massage_key_push = new Massage_key_push(layer);
    massage_key_not_work = new Massage_key_not_work(layer);
}

void Tracker::Checking_the_state(States_game state, std::vector<Logger*> logger) {
    switch (state) {
        case States_game::kSTART:
            render.Print_start();
            break;
        case States_game::kLOGGER:
            render.Print_logger();
            break;
        case States_game::kCHOOSE_LOGGER:
            render.Print_choose_logger();
            break;
        case States_game::kLEVEL:
            render.Print_level();
            break;
        case States_game::kGAME:
            Make_log(logger, massage_new_game);
            break;
        case States_game::kPLAY:
            render.Print_player(player);
            render.Print_playing_field(player, field);
            render.Print_game();
            break;
        case States_game::kLOOSE:
            render.Print_lose();
            Make_log(logger, massage_lose);
            break;
        case States_game::kWIN:
            render.Print_win();
            Make_log(logger, massage_win);
            break;
        case States_game::kNEW:
            render.Print_new_game();
            break;
        case States_game::kEND:
            render.Print_the_end();
            break;
        case States_game::kKEY:
            render.Clear();
            Make_log(logger, massage_key_not_work);
            break;
        case States_game::kKEY_COMMAND:
            render.Clear();
            Make_log(logger, massage_key_push);
            break;
    }
}

void Tracker::Make_log(std::vector<Logger*> logger, Massage* massage) {
    for(int i = 0; i < logger.size(); i++){
        logger[i]->log(massage);
    }
}

Tracker::~Tracker() {
    if(massage_win != nullptr){
        delete massage_win;
    }
    if(massage_lose != nullptr){
        delete massage_lose;
    }
    if(massage_new_game != nullptr){
        delete massage_new_game;
    }
    if(massage_key_push != nullptr){
        delete massage_key_push;
    }
    if(massage_key_not_work != nullptr){
        delete massage_key_not_work;
    }
}

