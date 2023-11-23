#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "enum_states_walk.h"
#include "player.h"
#include "playing_field.h"

class Controller{
private:
    Player& person;
    Field& field;
public:
    Controller(Player& person, Field& field);
    void Walking(Joystick value);

    void change_health(int ValueC_Health);
    void change_points(int ValueC_Points);
    void change_level(int ValueC_Level);
};

#endif