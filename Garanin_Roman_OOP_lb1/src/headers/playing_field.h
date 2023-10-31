#ifndef OOP_HEADERS_FIELD_H_
#define OOP_HEADERS_FIELD_H_

#include "cell.h"
#include "player.h"

#define MIN_WIDTH 5
#define MIN_HEIGHT 5

class Field {
public:
    bool check(int x, int y) const;

    int get_width() const;
    int get_height() const;
    Cell& get_cell(int x, int y) const;
    int get_entrance_x() const;
    int get_entrance_y() const;
    int get_exit_x() const;
    int get_exit_y() const;

    void set_entrance(int x, int y);
    void set_exit(int x, int y);

    void print_field(Player& player) const;

    Field& operator = (const Field& other);
    Field& operator = (Field&& other) noexcept;

    Field(const Field& other);
    Field(Field&& other) noexcept;
    Field(int width = MIN_WIDTH, int height = MIN_HEIGHT);
    ~Field();
    
private:
    Cell** cells_;
    int width_, height_;
    int entrance_x_, entrance_y_;
    int exit_x_, exit_y_;
};

#endif