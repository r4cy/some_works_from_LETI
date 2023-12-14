#ifndef MASSAGE_LOG_NEW_GAME_H_
#define MASSAGE_LOG_NEW_GAME_H_

#include "massage.h"
#include "playing_field.h"

class Massage_log_new_game: public Massage{
private:
    Field& field;

public:
    Massage_log_new_game(Field& Value_field);
    std::string Get_MASSAGE() override;

};


#endif
