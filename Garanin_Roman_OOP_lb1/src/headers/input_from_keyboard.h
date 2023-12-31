#ifndef INPUT_FROM_CONSOLE_H_
#define INPUT_FROM_CONSOLE_H_

#include "conio.h"
#include <cctype>

#include "input_interface.h"

class Input_from_keyboard: public Input_Interface{
public:
    char Input_function() const override;
};

#endif
