#include <iostream>
#include "headers/player.h"

Player::Player(){
    health = kMAX_health;
    points = kSTART_points;
    level = 1;
    x = kSTART_x;
    y = kSTART_y;
}

int Player::Get_Health() const{
    return health;
}
int Player::Set_Health(int valueHealth){
    if(valueHealth > kMAX_health){
        health = kMAX_health;
        return 0;
    }
    if(valueHealth <= 0){
        health = 0;
        return 1;
    }
    health = valueHealth;
    return 0;
}


int Player::Get_Points() const{
    return points;
}
int Player::Set_Points(int valuePoints){
    if(valuePoints < kSTART_points){
        return 1;
    }
    points = valuePoints;
    return 0;
}


int Player::Get_Level() const{
    return level;
}
int Player::Set_Level(int valueLevel){
    if(valueLevel > kMAX_level || valueLevel <= 0){
        return 1;
    }
    level = valueLevel;
    return 0;
}


int Player::Get_X() const{
    return x;
}
void Player::Set_X(int valueX){
    x = valueX;
}


int Player::Get_Y() const{
    return y;
}
void Player::Set_Y(int valueY){
    y = valueY;
}

void Player::Set_X_Y(int valueX, int valueY){
    x = valueX;
    y = valueY;
}
