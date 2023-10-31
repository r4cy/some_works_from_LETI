#ifndef OOP_HEADERS_EVENT_H_
#define OOP_HEADERS_EVENT_H_

class Controller;

class Event{
public:
    virtual void start(Controller& control) = 0;
    virtual Event* create() const = 0;
};

#endif