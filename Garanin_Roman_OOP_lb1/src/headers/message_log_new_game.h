#ifndef MESSAGE_LOG_NEW_GAME_H_
#define MESSAGE_LOG_NEW_GAME_H_

#include "message.h"
#include "playing_field.h"

class Message_log_new_game: public Message{
private:
    Field& field;

public:
    Message_log_new_game(Field& Value_field);
    std::string Get_MESSAGE() override;
};


#endif
