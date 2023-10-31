#ifndef PLAYER_H_
#define PLAYER_H_

#include "states_walk.h"

class Player{
private:
    int health;
    int points;
    int level;
    int x;
    int y;
    const int kMAX_health = 100;
    const int kSTART_points = 0;
    const int kMAX_level = 5;
    const int kSTART_x = 0;
    const int kSTART_y = 0;


public:

    Player();

    int Get_Health() const;
    int Set_Health(int valueHealth);


    int Get_Points() const;
    int Set_Points(int valuePoints);


    int Get_Level() const;
    int Set_Level(int valueLevel);


    int Get_X() const;
    void Set_X(int valueX);


    int Get_Y() const;
    void Set_Y(int valueY);

    void Set_X_Y(int valueX, int valueY);

    char PRINT_VALUES();
};

#endif