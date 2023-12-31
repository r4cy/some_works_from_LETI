#include <iostream>
#include "headers/controller.h"


Controller::Controller(Player& valueP, Field& valueF) : person(valueP), field(valueF){
    person.Set_X(field.Get_Entrance_X());
    person.Set_Y(field.Get_Entrance_Y());
}

void Controller::Walking(Joystick value){
    int temporary_x = person.Get_X();
    int temporary_y = person.Get_Y();
    switch (value){
        case Joystick::kUP:
            temporary_y -= 1;
            // std::cout<<"STEP UP!\n\n";
            break;
        case Joystick::kDOWN:
            temporary_y += 1;
            // std::cout<<"STEP DOWN!\n\n";
            break;
        case Joystick::kLEFT:
            temporary_x -= 1;
            // std::cout<<"STEP LEFT!\n\n";
            break;
        case Joystick::kRIGHT:
            temporary_x += 1;
            // std::cout<<"STEP RIGHT!\n\n";
            break;
        default:
            std::cout<<"ERROR, UNIDENTIFIED STEP!\n\n";
            break;
    }
    
    if(field.check(temporary_x, temporary_y) && field.Get_Cell(temporary_x, temporary_y).Get_State_of_cell()){
        person.Set_X_Y(temporary_x,temporary_y);
        if(field.Get_Cell(temporary_x, temporary_y).CHECK_EVENT()){
            field.Get_Cell(temporary_x, temporary_y).Launch(*this);
        }
    }
}

void Controller::change_health(int ValueC_Health){
    int health = person.Get_Health();
    person.Set_Health(health+ValueC_Health);
}

void Controller::change_points(int ValueC_Points){
    int points = person.Get_Points();
    person.Set_Points(points+ValueC_Points);
}

void Controller::change_level(int ValueC_Level){
    int level = person.Get_Level();
    person.Set_Level(level+ValueC_Level);
}
