#include "headers/massage_log_win.h"

Massage_log_win::Massage_log_win(Player &Value_player) : player(Value_player) {}

std::string Massage_log_win::Get_MASSAGE() {
    return "Player WIN! Health = " + std::to_string(player.Get_Health()) + ", Points = " + std::to_string(player.Get_Points());
}
