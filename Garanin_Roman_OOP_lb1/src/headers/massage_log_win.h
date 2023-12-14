#ifndef MASSAGE_LOG_WIN_H_
#define MASSAGE_LOG_WIN_H_

#include "massage.h"
#include "player.h"

class Massage_log_win: public Massage {
private:
    Player& player;

public:
    Massage_log_win(Player& Value_player);
    std::string Get_MASSAGE() override;
};


#endif
