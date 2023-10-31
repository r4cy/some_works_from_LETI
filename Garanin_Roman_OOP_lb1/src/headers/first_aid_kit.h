#ifndef OOP_HEADERS_EVENT_HEALTH_H_
#define OOP_HEADERS_EVENT_HEALTH_H_

#include "event.h"

class First_aid_kit: public Event {
public:
    void start (Controller& control) override;
    Event* create() const override;
};

#endif