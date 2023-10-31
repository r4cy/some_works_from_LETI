#include <iostream>
#include "headers/controller.h"


Controller::Controller(Player& valueP, Field& valueF) : person(valueP), field(valueF){
    valueP.Set_X(field.get_entrance_x());
    valueP.Set_Y(field.get_entrance_y());
}

void Controller::Walking(Joystick value){
    int temporary_x = person.Get_X();
    int temporary_y = person.Get_Y();
    switch (value){
        case Joystick::kUP:
            temporary_y += 1;
            std::cout<<"STEP UP!\n\n";
            break;
        case Joystick::kDOWN:
            temporary_y -= 1;
            std::cout<<"STEP DOWN!\n\n";
            break;
        case Joystick::kLEFT:
            temporary_x -= 1;
            std::cout<<"STEP LEFT!\n\n";
            break;
        case Joystick::kRIGHT:
            temporary_x += 1;
            std::cout<<"STEP RIGHT!\n\n";
            break;
        default:
            std::cout<<"ERROR, UNCORRECT STEP!\n\n";
            break;
    }
    person.Set_X_Y(temporary_x,temporary_y);
}

void Controller::change_health(int valueC_Health){
    int health = person.Get_Health();
    person.Set_Health(health+valueC_Health);
}

void Controller::change_points(int valueC_Points){
    int points = person.Get_Points();
    person.Set_Points(points+valueC_Points);
}

void Controller::change_level(int ValueC_Level){
    int level = person.Get_Level();
    person.Set_Level(level+ValueC_Level);
}
