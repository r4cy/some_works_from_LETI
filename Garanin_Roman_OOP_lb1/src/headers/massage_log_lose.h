#ifndef LOG_LOSE_H_
#define LOG_LOSE_H_

#include "massage.h"
#include "player.h"

class Massage_log_lose: public Massage{
private:
    Player& player;

public:
    Massage_log_lose(Player& Value_player);
    std::string Get_MASSAGE() override;

};


#endif
