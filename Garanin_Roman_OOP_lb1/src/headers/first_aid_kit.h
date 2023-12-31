#ifndef FIRST_AID_KIT_H_
#define FIRST_AID_KIT_H_

#include "event.h"

class First_aid_kit: public Event {
public:
    void start(Controller& control) override;
    Event* create() const override;
};

#endif