#ifndef LOGGER_H_
#define LOGGER_H_

#include "massage.h"

class Logger{
public:
    virtual void log(Massage* massage) = 0;
};

#endif
