#include "headers/game.h"
#include <string>
#include "headers/input_from_keyboard.h"

int main() {
    Input_from_keyboard input;
    std::string filename = "D:\\LETI_works\\OOP_works_c++\\Works_from_LETI\\Garanin_Roman_OOP_lb1\\src\\control_keys";
    Interlayer layer(input, filename);
    Game new_game(layer);
    new_game.Begin();
    return 0;
}