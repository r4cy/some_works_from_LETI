#include "headers/controller.h"
#include "headers/teleport.h"

void Teleport::start(Controller& control) {
    control.Walking(Joystick::kDOWN);
    control.Walking(Joystick::kDOWN);
    control.Walking(Joystick::kDOWN);
}

Event* Teleport::create() const {
    return new Teleport;
}