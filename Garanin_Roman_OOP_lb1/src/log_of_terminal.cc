#include "headers/log_of_terminal.h"

void Log_of_terminal::log(Message *message) {
    std::cout << message->Get_MESSAGE() << std::endl;
}
