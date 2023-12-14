#ifndef MESSAGE_LOG_LOSE_H_
#define MESSAGE_LOG_LOSE_H_

#include "message.h"
#include "player.h"

class Message_log_lose: public Message{
private:
    Player& player;

public:
    Message_log_lose(Player& Value_player);
    std::string Get_MESSAGE() override;
};


#endif
