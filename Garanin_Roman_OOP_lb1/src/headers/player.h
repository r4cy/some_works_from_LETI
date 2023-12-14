#ifndef PLAYER_H_
#define PLAYER_H_

#include "enum_states_walk.h"

#define kMAX_health 100
#define kSTART_points 0
#define kMAX_level 5
#define kSTART_x 0
#define kSTART_y 0

class Player{
private:
    int health;
    int points;
    int level;
    int x;
    int y;


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
};

#endif