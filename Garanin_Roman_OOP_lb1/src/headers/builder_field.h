#ifndef BUILDER_FIELD_H_
#define BUILDER_FIELD_H_

#include "playing_field.h"
#include "first_aid_kit.h"
#include "mine.h"
#include "teleport.h"

class FieldCreator {
private:
    Mine event_M;
    Teleport event_T;
    First_aid_kit event_F;

public:
    Field Create_of_lvl1();
    Field Create_of_lvl2();
};

#endif