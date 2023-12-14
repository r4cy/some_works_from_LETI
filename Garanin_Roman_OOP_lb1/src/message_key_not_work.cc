#include "headers/message_key_not_work.h"

Message_key_not_work::Message_key_not_work(Interlayer &Value_layer): layer(Value_layer){}

std::string Message_key_not_work::Get_MESSAGE() {
    return "A key has been entered = " + std::string(1, layer.Get_last_button()) + " but nothing worked.";
}
