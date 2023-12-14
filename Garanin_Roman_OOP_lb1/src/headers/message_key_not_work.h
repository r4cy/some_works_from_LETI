#ifndef MESSAGE_KEY_NOT_WORK_H_
#define MESSAGE_KEY_NOT_WORK_H_

#include "message.h"
#include "interlayer.h"

class Message_key_not_work: public Message{
private:
    Interlayer& layer;

public:
    Message_key_not_work(Interlayer& Value_layer);
    std::string Get_MESSAGE() override;

};


#endif
