#ifndef LOGGER_H_
#define LOGGER_H_

#include "message.h"

class Logger{
public:
    virtual void log(Message* message) = 0;
};

#endif
