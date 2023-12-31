#include "headers/message_log_lose.h"

Message_log_lose::Message_log_lose(Player& Value_player): player(Value_player) {}

std::string Message_log_lose::Get_MESSAGE() {
    return "Player LOSE! X, Y = " + std::to_string(player.Get_X()) + ", " + std::to_string(player.Get_Y());
}
