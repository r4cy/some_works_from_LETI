#include "headers/controller.h"
#include "headers/builder_field.h"

int main() {
    FieldCreator level;
    Player player;
    Field field(level.Create_of_lvl1());
    Controller control(player, field);

    player.PRINT_VALUES();

    control.Walking(Joystick::kDOWN);
    control.Walking(Joystick::kDOWN);
    control.Walking(Joystick::kDOWN);
    control.Walking(Joystick::kDOWN);
    control.Walking(Joystick::kDOWN);
    control.Walking(Joystick::kDOWN);

    player.PRINT_VALUES();
    control.Walking(Joystick::kDOWN);
    return 0;
}