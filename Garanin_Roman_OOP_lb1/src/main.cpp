#include <iostream>

#include "headers/controller.h"
#include "headers/builder_field.h"

int main() {
    FieldCreator level;
    Player player;
    Field field(level.level_two());
    Controller control(player, field);

    player.PRINT_VALUES();

    control.Walking(Joystick::kDOWN);
    control.Walking(Joystick::kDOWN);
    control.Walking(Joystick::kDOWN);

    player.PRINT_VALUES();
    return 0;
}