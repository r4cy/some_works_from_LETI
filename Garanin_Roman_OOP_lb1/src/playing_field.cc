#include <iostream>

#include "headers/playing_field.h"

bool Field::check(int x, int y) const {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) 
        return false;
    return true;
}

int Field::get_width() const { 
    return width_; 
}

int Field::get_height() const { 
    return height_; 
}

Cell& Field::get_cell(int x, int y) const {
    return cells_[x][y];
}

int Field::get_entrance_x() const { 
    return entrance_x_; 
}

int Field::get_entrance_y() const { 
    return entrance_y_; 
}

int Field::get_exit_x() const { 
    return exit_x_; 
}

int Field::get_exit_y() const { 
    return exit_y_; 
}

void Field::set_entrance(int x, int y) {
    if (check(x, y) && cells_[x][y].get_passability()) {
        entrance_x_ = x;
        entrance_y_ = y;
    } else
        std::cout << "Invalid entrance coordinates!" << std::endl;
}

void Field::set_exit(int x, int y) {
    if (check(x, y) && cells_[x][y].get_passability()) {
        exit_x_ = x;
        exit_y_ = y;
    } else
        std::cout << "Invalid exit coordinates!" << std::endl;
}

void Field::print_field(Player& player) const {
     for (int y = 0; y < width_; y++) {
        for (int x = 0; x < height_; x++) {
            if (player.Get_X() == x && player.Get_Y() == y)
                std::cout << "P ";
            else if (entrance_x_ == x && entrance_y_ == y)
                std::cout << "S ";
            else if (exit_x_ == x && exit_y_ == y)
                std::cout << "F ";
            else if (cells_[x][y].get_event()) 
                std::cout << "? ";
            else if (cells_[x][y].get_passability())
                std::cout << ". ";
            else 
                std::cout << "# ";
        }
        std::cout << std::endl;
    }
}

Field& Field::operator = (const Field& other) {
    if (this != &other) {
        if (cells_ != nullptr) {
            for (int x = 0; x < width_; x++) 
                delete[] cells_[x];
            delete[] cells_;
        }

        width_ = other.width_;
        height_ = other.height_;
        entrance_x_ = other.entrance_x_;
        entrance_y_ = other.entrance_y_;
        exit_x_ = other.exit_x_;
        exit_y_ = other.exit_y_;
        if (width_ >= MIN_WIDTH && height_ >= MIN_HEIGHT) {
            cells_ = new Cell*[width_];
            for (int x = 0; x < width_; x++) {
                cells_[x] = new Cell[height_];
                for (int y = 0; y < height_; y++) 
                    cells_[x][y] = other.cells_[x][y];
            }
        } else
            std::cout << "Invalid field size!" << std::endl;
    }
    return *this;
}

Field& Field::operator = (Field&& other) noexcept {
    if (this != &other) {
        if (cells_ != nullptr) {
            for (int x = 0; x < width_; x++) 
                delete[] cells_[x];
            delete[] cells_;
        }

        std::swap(width_, other.width_);
        std::swap(height_, other.height_);
        std::swap(entrance_x_, other.entrance_x_);
        std::swap(entrance_y_, other.entrance_y_);
        std::swap(exit_x_, other.exit_x_);
        std::swap(exit_y_, other.exit_y_);
        std::swap(cells_, other.cells_);
    }
    return *this;
}

Field::Field(const Field& other) : width_(other.width_), height_(other.height_), entrance_x_(other.entrance_x_), entrance_y_(other.entrance_y_), exit_x_(other.exit_x_), exit_y_(other.exit_y_) {
   if (width_ >= MIN_WIDTH && height_ >= MIN_HEIGHT) {
        cells_ = new Cell*[width_];
        for (int x = 0; x < width_; x++) {
            cells_[x] = new Cell[height_];
            for (int y = 0; y < height_; y++) 
                cells_[x][y] = other.cells_[x][y];
        }
   } else
        std::cout << "Invalid field size!" << std::endl;
}

Field::Field(Field&& other) noexcept {
    std::swap(width_, other.width_);
    std::swap(height_, other.height_);
    std::swap(entrance_x_, other.entrance_x_);
    std::swap(entrance_y_, other.entrance_y_);
    std::swap(exit_x_, other.exit_x_);
    std::swap(exit_y_, other.exit_y_);
    std::swap(cells_, other.cells_);
}

Field::Field(int width, int height) : width_(width), height_(height) {
    if (width >= MIN_WIDTH && height >= MIN_HEIGHT) {
        cells_ = new Cell*[width];
        for (int i = 0; i < width; i++)
            cells_[i] = new Cell[height];
    } else 
        std::cout << "Invalid field size!" << std::endl;
}

Field::~Field() {
    if (cells_ != nullptr) {
        for (int i = 0; i < width_; i++)
            delete[] cells_[i];
        delete[] cells_;
    }
}