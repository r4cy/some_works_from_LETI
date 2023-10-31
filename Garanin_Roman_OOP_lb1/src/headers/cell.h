#ifndef OOP_HEADERS_CELL_H_
#define OOP_HEADERS_CELL_H_

#include "event.h"

class Cell {
private:
    bool passability_;
    Event* event_;

public:
    bool get_passability() const;
    bool get_event() const;
    void set_passability(bool passability); 
    void set_event(Event* event);

    void execute_event(Controller& control);

    Cell& operator = (const Cell& other); 
    Cell& operator = (Cell&& other) noexcept; 

    Cell(const Cell& other);
    Cell(Cell&& other) noexcept; 
    Cell(bool passability = true, Event* event = nullptr);
    ~Cell();


};

#endif