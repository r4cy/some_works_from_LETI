#include "headers/controller.h"
#include "headers/first_aid_kit.h"

void First_aid_kit::start(Controller& control) {
    control.change_health(15);
    control.change_points(2);
}

Event* First_aid_kit::create() const {
    return new First_aid_kit;
}