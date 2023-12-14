#ifndef MESSAGE_KEY_PUSH_H_
#define MESSAGE_KEY_PUSH_H_

#include "message.h"
#include "interlayer.h"

class Message_key_push: public Message{
private:
    Interlayer& layer;
    std::unordered_map<Action, std::string> command;

public:
    Message_key_push(Interlayer& Value_layer);
    std::string Get_MESSAGE() override;
};


#endif
