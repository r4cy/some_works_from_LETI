#include "headers/controller.h"
#include "headers/builder_field.h"

Field FieldCreator::level_one() {
    Field field(10, 10);

    field.set_entrance(0, 0);
    field.set_exit(4, 4);

    for (int y = 0; y < 3; y++)
        field.get_cell(1, y).set_passability(false);
    field.get_cell(0, 4).set_passability(false);
    field.get_cell(2, 1).set_passability(false);
    field.get_cell(2, 4).set_passability(false);
    field.get_cell(3, 1).set_passability(false);
    field.get_cell(3, 3).set_passability(false);

    field.get_cell(1, 4).set_event(event_F.create());
    field.get_cell(3, 4).set_event(event_M.create());
    field.get_cell(2, 0).set_event(event_T.create());

    return field;
}

Field FieldCreator::level_two() {
    Field field(15, 15);

    field.set_entrance(0, 4);
    field.set_exit(4, 0);

    field.get_cell(0, 0).set_passability(false);
    field.get_cell(0, 1).set_passability(false);
    field.get_cell(1, 3).set_passability(false);
    for (int y = 0; y < 4; y++)
        field.get_cell(2, y).set_passability(false);
    field.get_cell(3, 1).set_passability(false);
    field.get_cell(4, 3).set_passability(false);

    return field;
}