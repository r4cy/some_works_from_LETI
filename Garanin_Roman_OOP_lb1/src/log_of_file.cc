#include "headers/log_of_file.h"

Log_of_file::Log_of_file() {
    file.open("file_for_log");
    if(!file.is_open()){
        std::cout << "ERROR TO OPEN LOG FILE!" << std::endl;
    }
}

void Log_of_file::log(Message *message) {
    file << message->Get_MESSAGE() << std::endl;
}

Log_of_file::~Log_of_file() {
    if(file.is_open()){
        file.close();
    }
}
