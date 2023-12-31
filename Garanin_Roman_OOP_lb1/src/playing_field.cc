#include <iostream>

#include "headers/playing_field.h"

Field::Field(int Value_Width, int Value_Length) : width(Value_Width), length(Value_Length) {
    if (width >= MIN_WIDTH && length >= MIN_LENGTH) {
        cell = new Cell*[width];
        for (int i = 0; i < width; i++){
            cell[i] = new Cell[length];
        }
        Set_Entrance(0, 0);
        Set_Exit(0, length-1);
    }else{
        std::cout << "" << std::endl;
    }
}

Field& Field::operator = (const Field& other){
    if (this != &other) {
        for (int x = 0; x < width; x++){
            delete[] cell[x];
        }
        delete[] cell;

        width = other.width;
        length = other.length;
        entrance_x = other.entrance_x;
        entrance_y = other.entrance_y;
        exit_x = other.exit_x;
        exit_y = other.exit_y;
        if (width >= MIN_WIDTH && length >= MIN_LENGTH) {
            cell = new Cell*[width];
            for (int x = 0; x < width; x++){
                cell[x] = new Cell[length];
                for (int y = 0; y < width; y++){
                    cell[x][y] = other.cell[x][y];
                }
            }
        }else{
            std::cout << "Invalid field size!" << std::endl;
        }
    }
    return *this;
}

Field& Field::operator = (Field&& other) noexcept {
    if (this != &other) {
        for (int x = 0; x < width; x++){
            delete[] cell[x];
        }
        delete[] cell;

        std::swap(width, other.width);
        std::swap(length, other.length);
        std::swap(entrance_x, other.entrance_x);
        std::swap(entrance_y, other.entrance_y);
        std::swap(exit_x, other.exit_x);
        std::swap(exit_y, other.exit_y);
        std::swap(cell, other.cell);

        other.width = 0;
        other.length = 0;
        other.entrance_x = 0;
        other.entrance_y = 0;
        other.exit_x = 0;
        other.exit_y = 0;
        other.cell = nullptr;
    }
    return *this;
}

Field::Field(const Field& other) : width(other.width), length(other.length), entrance_x(other.entrance_x), entrance_y(other.entrance_y), exit_x(other.exit_x), exit_y(other.exit_y){
    if (width >= MIN_WIDTH && length >= MIN_LENGTH) {
        cell = new Cell*[width];
        for (int x = 0; x < width; x++) {
            cell[x] = new Cell[length];
            for (int y = 0; y < length; y++)
                cell[x][y] = other.cell[x][y];
        }
    } else
        std::cout << "Invalid field size!" << std::endl;
}

Field::Field(Field&& other) noexcept {
    std::swap(width, other.width);
    std::swap(length, other.length);
    std::swap(entrance_x, other.entrance_x);
    std::swap(entrance_y, other.entrance_y);
    std::swap(exit_x, other.exit_x);
    std::swap(exit_y, other.exit_y);
    std::swap(cell, other.cell);
}

bool Field::check(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= length)
        return false;
    return true;
}

int Field::Get_Width() const {
    return width;
}

int Field::Get_Length() const {
    return length;
}

Cell& Field::Get_Cell(int x, int y) const {
    return cell[x][y];
}

void Field::Set_Entrance(int x, int y) {
    if (check(x, y) && cell[x][y].Get_State_of_cell()) {
        entrance_x = x;
        entrance_y = y;
    } else
        std::cout << "Invalid entrance coordinates!" << std::endl;
}

int Field::Get_Entrance_X() const {
    return entrance_x;
}

int Field::Get_Entrance_Y() const {
    return entrance_y;
}

void Field::Set_Exit(int x, int y) {
    if (check(x, y) && cell[x][y].Get_State_of_cell()) {
        exit_x = x;
        exit_y = y;
    } else
        std::cout << "Invalid exit coordinates!" << std::endl;
}

int Field::Get_Exit_X() const {
    return exit_x;
}

int Field::Get_Exit_Y() const {
    return exit_y;
}

void Field::PRINT_FIELD(Player& player) const {
     for (int y = 0; y < width; y++) {
        for (int x = 0; x < length; x++) {
            if(player.Get_X() == x && player.Get_Y() == y){
                std::cout << "P ";
            }else if(entrance_x == x && entrance_y == y){
                std::cout << "[]";
            }else if(exit_x == x && exit_y == y){
                std::cout << "{}";
            }else if(Get_Cell(x, y).CHECK_EVENT()){
                std::cout << "@ ";
            } else if(!Get_Cell(x, y).Get_State_of_cell()){
                std::cout << "# ";
            }else{
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

Field::~Field() {
    if (cell != nullptr) {
        for (int i = 0; i < width; i++){
            delete[] cell[i];
        }
        delete[] cell;
    }
}