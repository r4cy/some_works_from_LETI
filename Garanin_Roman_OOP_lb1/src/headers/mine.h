#ifndef OOP_HEADERS_EVENT_SCORE_H_
#define OOP_HEADERS_EVENT_SCORE_H_

#include "event.h"

class Mine: public Event {
public:
    void start(Controller& control) override;
    Event* create() const override;
};

#endif