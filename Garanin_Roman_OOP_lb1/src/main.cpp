#include "game.h"
#include "input_from_keyboard.h"

int main() {
    Input_from_keyboard input;
    Interlayer layer(input, "./control_keys");
    Game new_game(layer);
    new_game.Begin();
    return 0;
}