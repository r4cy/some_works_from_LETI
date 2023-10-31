#ifndef OOP_HEADERS_FIELD_CREATOR_H_
#define OOP_HEADERS_FIELD_CREATOR_H_

#include "playing_field.h"
#include "first_aid_kit.h"
#include "mine.h"
#include "teleport.h"

class FieldCreator {
private:
    First_aid_kit event_F;
    Mine event_M;
    Teleport event_T;

public:
    Field level_one();
    Field level_two();
};

#endif