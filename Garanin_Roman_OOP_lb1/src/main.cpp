#include "headers/game.h"
#include "headers/terminal_render.h"
#include "headers/input_from_keyboard.h"

int main() {
    Input_from_keyboard input;
    Terminal_render render;
    Game new_game(input, render);
    new_game.Begin();
    return 0;
}