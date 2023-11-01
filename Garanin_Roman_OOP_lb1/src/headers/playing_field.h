#ifndef PLAYING_FIELD_H_
#define PLAYING_FIELD_H_

#include "cell.h"
#include "player.h"

#define MIN_WIDTH 5
#define MIN_LENGTH 5

class Field {
private:
    Cell** cell;
    int width, length;
    int entrance_x, entrance_y;
    int exit_x, exit_y;


public:
    Field(int width = MIN_WIDTH, int height = MIN_LENGTH);

    Field(const Field& other);
    Field(Field&& other) noexcept;
    Field& operator = (const Field& other);
    Field& operator = (Field&& other) noexcept;

    bool check(int x, int y) const;

    int Get_Width() const;
    int Get_Length() const;

    Cell& Get_Cell(int x, int y) const;

    void Set_Entrance(int x, int y);
    int Get_Entrance_X() const;
    int Get_Entrance_Y() const;

    void Set_Exit(int x, int y);
    int Get_Exit_X() const;
    int Get_Exit_Y() const;

    void PRINT_FIELD(Player& player) const;

    ~Field();
};

#endif