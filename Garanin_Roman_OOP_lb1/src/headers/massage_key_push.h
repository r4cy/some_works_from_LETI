#ifndef GARANIN_ROMAN_OOP_LB_MASSAGE_KEY_PUSH_H
#define GARANIN_ROMAN_OOP_LB_MASSAGE_KEY_PUSH_H

#include "massage.h"
#include "interlayer.h"

class Massage_key_push: public Massage{
private:
    Interlayer& layer;
    std::unordered_map<Action, std::string> command;

public:
    Massage_key_push(Interlayer& Value_layer);
    std::string Get_MASSAGE() override;

};


#endif
