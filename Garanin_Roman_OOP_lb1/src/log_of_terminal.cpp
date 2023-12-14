#include "headers/log_of_terminal.h"

void Log_of_terminal::log(Massage *massage) {
    std::cout << massage->Get_MASSAGE() << std::endl;
}
