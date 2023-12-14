#ifndef MASSAGE_KEY_NOT_WORK_H_
#define MASSAGE_KEY_NOT_WORK_H_

#include "massage.h"
#include "interlayer.h"

class Massage_key_not_work: public Massage{
private:
    Interlayer& layer;

public:
    Massage_key_not_work(Interlayer& Value_layer);
    std::string Get_MASSAGE() override;

};


#endif
