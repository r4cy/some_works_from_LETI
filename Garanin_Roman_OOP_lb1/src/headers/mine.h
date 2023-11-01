#ifndef MINE_H_
#define MINE_H_

#include "event.h"

class Mine: public Event {
public:
    void start(Controller& control) override;
    Event* create() const override;
};

#endif