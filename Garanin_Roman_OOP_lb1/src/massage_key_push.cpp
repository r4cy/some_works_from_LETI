#include "headers/massage_key_push.h"

Massage_key_push::Massage_key_push(Interlayer &Value_layer): layer(Value_layer) {
    command[Action::kMOVE_up] = "UP";
    command[Action::kMOVE_down] = "DOWN";
    command[Action::kMOVE_left] = "LEFT";
    command[Action::kMOVE_right] = "RIGHT";
    command[Action::kGO_quit] = "QUIT";
    command[Action::kSAY_yes] = "YES";
    command[Action::kSAY_no] = "NO";
}

std::string Massage_key_push::Get_MASSAGE() {
    return "A key has been entered = " + std::string(1, layer.Get_last_button()) + " after that, the command worked = " + command[layer.Get_last_actions()];
}
