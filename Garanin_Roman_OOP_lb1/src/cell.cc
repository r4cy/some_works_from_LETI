#include <iostream>
#include "headers/cell.h"

Cell::Cell(bool Value_state_of_cell, Event* Value_event) : state_of_cell(Value_state_of_cell), event(Value_event) {}

Cell::Cell(const Cell& other) : state_of_cell(other.state_of_cell), event(other.event) {}

Cell::Cell(Cell&& other) noexcept {
    std::swap(state_of_cell, other.state_of_cell);
    std::swap(event, other.event);
    other.state_of_cell = 0;
    other.event = nullptr;
}

Cell& Cell::operator = (const Cell& other) {
    if (this != &other) {
        state_of_cell = other.state_of_cell;
        DELETE_OF_CELL();
        event = other.event;
    }
    return *this;
}

Cell& Cell::operator = (Cell&& other) noexcept {
    if (this != &other) {
        std::swap(state_of_cell, other.state_of_cell);
        DELETE_OF_CELL();
        std::swap(event, other.event);
        other.state_of_cell = 0;
        other.event = nullptr;
    }
    return *this;
}

void Cell::Set_Event(Event* Value_event) {
    DELETE_OF_CELL();
    event = Value_event;
}

Event *Cell::Get_EVENT() {
    return event;
}

bool Cell::CHECK_EVENT() const {
    return event != nullptr;
}

void Cell::Set_State_of_cell(bool Value_state_of_cell) {
    state_of_cell = Value_state_of_cell;
}

bool Cell::Get_State_of_cell() const {
    return state_of_cell;
}

void Cell::Launch(Controller &control) {
    event->start(control);
    DELETE_OF_CELL();
}

void Cell::DELETE_OF_CELL() {
    if(event != nullptr){
        delete event;
        event = nullptr;
    }
}

Cell::~Cell() {
    DELETE_OF_CELL();
}