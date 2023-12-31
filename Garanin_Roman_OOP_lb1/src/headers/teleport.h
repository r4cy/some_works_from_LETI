#ifndef TELEPORT_H_
#define TELEPORT_H_

#include "event.h"

class Teleport: public Event{
public:
   void start(Controller& control) override;
   Event* create() const override;
};

#endif