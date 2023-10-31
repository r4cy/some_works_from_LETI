#ifndef OOP_HEADERS_EVENT_MOVE_H_
#define OOP_HEADERS_EVENT_MOVE_H_

#include "event.h"

class Teleport: public Event{
public:
   void start(Controller& control) override;
   Event* create() const override;
};

#endif