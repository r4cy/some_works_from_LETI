#include "headers/message_log_win.h"

Message_log_win::Message_log_win(Player &Value_player) : player(Value_player) {}

std::string Message_log_win::Get_MESSAGE() {
    return "Player WIN! Health = " + std::to_string(player.Get_Health()) + ", Points = " + std::to_string(player.Get_Points());
}
