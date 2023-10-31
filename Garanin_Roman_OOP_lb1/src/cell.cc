#include <iostream>
#include "headers/cell.h"

bool Cell::get_passability() const {
    return passability_;
}

bool Cell::get_event() const {
    return event_ != nullptr;
}

void Cell::set_passability(bool passability) {
    passability_ = passability;
}

void Cell::set_event(Event* event) {
    if (event_ != nullptr)
        delete event_;
    event_ = event;
}

void Cell::execute_event(Controller& control) {
    event_ -> start(control);
}

Cell& Cell::operator = (const Cell& other) {
    if (this != &other) {
        passability_ = other.passability_;
        if (event_ != nullptr)
            delete event_;
        event_ = other.event_ -> create();
    }
    return *this;
}

Cell& Cell::operator = (Cell&& other) noexcept {
    if (this != &other) {
        std::swap(passability_, other.passability_);
        if (event_ != nullptr)
            delete event_;
        std::swap(event_, other.event_);
    }
    return *this;
}

Cell::Cell(const Cell& other) : passability_(other.passability_), event_(other.event_ -> create()) {}

Cell::Cell(Cell&& other) noexcept {
    std::swap(passability_, other.passability_);
    std::swap(event_, other.event_);
}

Cell::Cell(bool passability, Event* event) : passability_(passability), event_(event) {}

Cell::~Cell() {
    if (event_ != nullptr)
        delete event_;
}