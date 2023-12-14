#include "headers/message_key_push.h"

Message_key_push::Message_key_push(Interlayer &Value_layer): layer(Value_layer) {
    command[Action::kMOVE_up] = "UP";
    command[Action::kMOVE_down] = "DOWN";
    command[Action::kMOVE_left] = "LEFT";
    command[Action::kMOVE_right] = "RIGHT";
    command[Action::kGO_quit] = "QUIT";
    command[Action::kSAY_yes] = "YES";
    command[Action::kSAY_no] = "NO";
    command[Action::kONE] = "1";
    command[Action::kTWO] = "2";
    command[Action::kTHREE] = "3";
}

std::string Message_key_push::Get_MESSAGE() {
    return "A key has been entered = " + std::string(1, layer.Get_last_button()) + " after that, the command worked = " + command[layer.Get_last_actions()];
}
