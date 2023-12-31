#include "headers/input_from_keyboard.h"

char Input_from_keyboard::Input_function() const{
    char symbol;
    while (true){
        if (kbhit()) {
            symbol = getch();
            break;
        }
    }
    return tolower(symbol);
}
