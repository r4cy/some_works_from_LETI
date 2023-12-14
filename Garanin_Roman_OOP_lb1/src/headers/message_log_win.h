#ifndef MESSAGE_LOG_WIN_H_
#define MESSAGE_LOG_WIN_H_

#include "message.h"
#include "player.h"

class Message_log_win: public Message {
private:
    Player& player;

public:
    Message_log_win(Player& Value_player);
    std::string Get_MESSAGE() override;
};


#endif
