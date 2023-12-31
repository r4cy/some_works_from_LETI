#ifndef INTERLAYER_H_
#define INTERLAYER_H_

#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>

#include "input_interface.h"
#include "enum_key_operations.h"

class Interlayer {
private:
    Input_Interface& input;
    char button;
    Action actions;
    std::unordered_map<char, Action> command;

    Action Decoding_action(const std::string& action);

public:
    Action Get_action();
    char Get_last_button() const;
    Action Get_last_actions() const;
    Interlayer(Input_Interface& input, const std::string& file_for_control);

};


#endif
