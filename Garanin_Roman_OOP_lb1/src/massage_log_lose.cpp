#include "headers/massage_log_lose.h"

Massage_log_lose::Massage_log_lose(Player& Value_player): player(Value_player) {}

std::string Massage_log_lose::Get_MASSAGE() {
    return "Player LOSE! X, Y = " + std::to_string(player.Get_X()) + ", " + std::to_string(player.Get_Y());
}
