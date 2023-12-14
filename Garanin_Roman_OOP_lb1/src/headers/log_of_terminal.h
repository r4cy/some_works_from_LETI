#ifndef LOG_OF_TERMINAL_H_
#define LOG_OF_TERMINAL_H_

#include <iostream>
#include "logger.h"

class Log_of_terminal: public Logger{
public:
    void log(Massage *massage) override;

};


#endif
