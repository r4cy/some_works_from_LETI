#include "headers/message_log_new_game.h"

Message_log_new_game::Message_log_new_game(Field &Value_field): field(Value_field) {}

std::string Message_log_new_game::Get_MESSAGE() {
    return "A new game is loaded! Size field (length, width) = " + std::to_string(field.Get_Length()) + ", " + std::to_string(field.Get_Width()) +
    + "; Start position (x, y) = " + std::to_string(field.Get_Entrance_X()) + ", " + std::to_string(field.Get_Entrance_Y());
}
