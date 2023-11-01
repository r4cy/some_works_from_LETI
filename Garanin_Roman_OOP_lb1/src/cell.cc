#include <iostream>
#include "headers/cell.h"

Cell::Cell(bool Value_state_of_cell, Event* Value_event) : state_of_cell(Value_state_of_cell), event(Value_event) {}

Cell::Cell(const Cell& other) : passability_(other.passability_), event_(other.event_ -> create()) {}

Cell::Cell(Cell&& other) noexcept {
    std::swap(state_of_cell, other.state_of_cell);
    std::swap(event, other.event);
}

Cell& Cell::operator = (const Cell& other) {
    if (this != &other) {
        passability_ = other.passability_;
        if (event_ != nullptr)
            delete event;
        event = other.event;
    }
    return *this;
}

Cell& Cell::operator = (Cell&& other) noexcept {
    if (this != &other) {
        std::swap(state_of_cell, other.state_of_cell);
        if (event != nullptr)
            delete event;
        std::swap(event, other.event);
    }
    return *this;
}

void Cell::Set_Event(Event* event) {
    if (event != nullptr)
        delete event;
    event = event;
}

bool Cell::States_of_cell() const {
    return event != nullptr;
}

void Cell::set_passability(bool passability) {
    passability_ = passability;
}

bool Cell::get_passability() const {
    return passability_;
}

void Cell::Launch(Controller &control) {
    event->start(control);
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