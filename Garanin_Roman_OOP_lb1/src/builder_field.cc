#include "headers/controller.h"
#include "headers/builder_field.h"

Field FieldCreator::Create_of_lvl1() {
    Field field(10, 10);

    return field;
}

Field FieldCreator::Create_of_lvl2() {
    Field field(15, 15);

    return field;
}