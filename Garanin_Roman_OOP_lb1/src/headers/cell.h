#ifndef CELL_H_
#define CELL_H_

#include "event.h"

class Cell {
private:
    bool state_of_cell;
    Event* event;


public:
    Cell(bool Value_state_of_cell = true, Event* Value_event = nullptr);

    Cell(const Cell& other);
    Cell(Cell&& other) noexcept;
    Cell& operator = (const Cell& other);
    Cell& operator = (Cell&& other) noexcept;

    void Set_Event(Event* Value_event);
    Event* Get_EVENT();
    bool CHECK_EVENT() const;
    void Set_State_of_cell(bool Value_state_of_cell);
    bool Get_State_of_cell() const;


    void Launch(Controller& control);

    void DELETE_OF_CELL();
    ~Cell();
};

#endif