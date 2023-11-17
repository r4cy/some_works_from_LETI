#include "interlayer.h"

Action Interlayer::Get_action() {
    char key = input.Input_function();
    Action action;
    if (command.count(key) == 0)
        action = Action::kUN_KNOW;
    else
        action = command[key];
    return action;
}

Interlayer::Interlayer(Input_Interface& Value_input, const std::string& file_for_control) : input(Value_input) {
    std::ifstream file(file_for_control);
    if (!file.is_open()) {
        std::cout << "Failed to open file" << std::endl;
        exit(0);
    }

    char key;
    std::string action;
    std::unordered_map<char, Action> actions_map;
    std::unordered_map<std::string, bool> action_assigned;

    action_assigned["UP"] = false;
    action_assigned["DOWN"] = false;
    action_assigned["LEFT"] = false;
    action_assigned["RIGHT"] = false;
    action_assigned["QUIT"] = false;
    action_assigned["YES"] = false;
    action_assigned["NO"] = false;

    while (file >> key >> action) {
        key = tolower(key);
        if (actions_map.count(key) > 0) {
            std::cout << "Error: Key " << key << " is assigned to multiple actions" << std::endl;
            exit(0);
        }
        if (action_assigned[action]) {
            std::cout << "Error: Action " << action << " is assigned to multiple keys" << std::endl;
            exit(0);
        }
        actions_map[key] = Decoding_action(action);
        action_assigned[action] = true;
    }

    for (const auto& pair : action_assigned) {
        if (!pair.second) {
            std::cout << "Error: Action " << pair.first << " is not assigned to any key" << std::endl;
            exit(0);
        }
    }
    command = actions_map;
    file.close();
}

Action Interlayer::Decoding_action(const std::string& action) {
    if (action == "up")
        return Action::kMOVE_up;
    else if (action == "DOWN")
        return Action::kMOVE_down;
    else if (action == "LEFT")
        return Action::kMOVE_left;
    else if (action == "RIGHT")
        return Action::kMOVE_right;
    else if (action == "QUIT")
        return Action::kGO_quit;
    else if (action == "YES")
        return Action::kSAY_yes;
    else if (action == "NO")
        return Action::kSAY_no;
    else
        return Action:: kUN_KNOW;
}
