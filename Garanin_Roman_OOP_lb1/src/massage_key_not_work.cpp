#include "headers/massage_key_not_work.h"

Massage_key_not_work::Massage_key_not_work(Interlayer &Value_layer): layer(Value_layer){}

std::string Massage_key_not_work::Get_MASSAGE() {
    return "A key has been entered = " + std::string(1, layer.Get_last_button()) + " but nothing worked.";
}
