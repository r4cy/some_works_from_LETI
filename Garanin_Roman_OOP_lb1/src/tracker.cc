#include <cstdlib>
#include <iostream>
#include "headers/tracker.h"

Tracker::Tracker(Interface_render& Value_render, Player& Value_player, Field& Value_field) : render(Value_render), player(Value_player), field(Value_field) {}

void Tracker::Checking_the_state(States_game state) const {
    switch (state) {
        case States_game::kSTART:
            render.Print_start();
            break;
        case States_game::kLEVEL:
            render.Print_level();
            break;
        case States_game::kPLAY:
            system("cls");
            render.Print_player(player);
            render.Print_playing_field(player, field);
            render.Print_game();
            break;
        case States_game::kLOOSE:
            render.Print_lose();
            break;
        case States_game::kWIN:
            render.Print_win();
            break;
        case States_game::kNEW:
            render.Print_new_game();
            break;
        case States_game::kEND:
            render.Print_the_end();
            break;
    }
}

