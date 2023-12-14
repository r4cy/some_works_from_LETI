#include "headers/massage_log_new_game.h"

Massage_log_new_game::Massage_log_new_game(Field &Value_field): field(Value_field) {}

std::string Massage_log_new_game::Get_MASSAGE() {
    return "The game was REBOOT! Size field (length, width) = " + std::to_string(field.Get_Length()) + ", " + std::to_string(field.Get_Width()) +
    + "; Start position (x, y) = " + std::to_string(field.Get_Entrance_X()) + ", " + std::to_string(field.Get_Entrance_Y());
}
