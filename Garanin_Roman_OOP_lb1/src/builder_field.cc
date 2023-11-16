#include "headers/controller.h"
#include "headers/builder_field.h"

Field FieldCreator::Create_of_lvl1() {
    Field field(8, 8);

    field.Get_Cell(1, 1).Set_State_of_cell(false);
    field.Get_Cell(2, 2).Set_State_of_cell(false);
    field.Get_Cell(2, 3).Set_State_of_cell(false);
    field.Get_Cell(3, 3).Set_State_of_cell(false);

    field.Get_Cell(0, 1).Set_Event(event_M.create());
    field.Get_Cell(0, 2).Set_Event(event_F.create());
    field.Get_Cell(0, 3).Set_Event(event_T.create());

    return field;
}

Field FieldCreator::Create_of_lvl2() {
    Field field(10, 10);

    field.Set_Entrance(field.Get_Width() - 1, 0);
    field.Set_Exit(field.Get_Width() - 1, field.Get_Length() - 1);

    field.Get_Cell(9, 2).Set_State_of_cell(false);
    field.Get_Cell(8, 2).Set_State_of_cell(false);

    field.Get_Cell(7, 2).Set_Event(event_M.create());
    field.Get_Cell(7, 3).Set_Event(event_F.create());
    field.Get_Cell(9, 8).Set_Event(event_T.create());

    return field;
}