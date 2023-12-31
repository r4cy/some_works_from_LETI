#ifndef EVENT_H_
#define EVENT_H_

class Controller;

class Event{
public:
    virtual void start(Controller& control) = 0;
    virtual Event* create() const = 0;
    virtual ~Event() = default;
};

#endif