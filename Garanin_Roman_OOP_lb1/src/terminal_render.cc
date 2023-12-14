#include "headers/terminal_render.h"

void Terminal_render::Print_start() const {
    std::cout << "Hello and Welcome in my Game!" << std::endl;
}

void Terminal_render::Print_logger() const {
    std::cout << "DO YOU NEED A LOGGER? (Y - YES, N - NO): " << std::endl;
}

void Terminal_render::Print_choose_logger() const {
    std::cout << "WHAT KIND OF LOGGER YOU WANT (1 - file, 2 - terminal, 3 - both): " << std::endl;
}

void Terminal_render::Print_level() const {
    std::cout << "Choose a level of map (1 or 2):" << std::endl;
}

void Terminal_render::Print_win() const {
    std::cout << "Congratulations, you have reached the finish line!" << std::endl;
}

void Terminal_render::Print_lose() const {
    std::cout << "You're dead!" << std::endl;
}

void Terminal_render::Print_player(Player& player) const {
    std::cout<<"Health = " << player.Get_Health() << "\nPoints = " << player.Get_Points() << "\nLevel = " << player.Get_Level() << "\nX, Y = " << player.Get_X() << ", " << player.Get_Y() << "\n\n";
}

void Terminal_render::Print_playing_field(Player& player, Field& field) const {
    for (int y = 0; y < field.Get_Width(); y++) {
        for (int x = 0; x < field.Get_Length(); x++) {
            if (player.Get_X() == x && player.Get_Y() == y)
                std::cout << "P ";
            else if (field.Get_Entrance_X() == x && field.Get_Entrance_Y() == y)
                std::cout << "[]";
            else if (field.Get_Exit_X() == x && field.Get_Exit_Y() == y)
                std::cout << "{}";
            else if (field.Get_Cell(x, y).CHECK_EVENT() && typeid(*field.Get_Cell(x, y).Get_EVENT()) == typeid(First_aid_kit))
                std::cout << "+ ";
            else if (field.Get_Cell(x, y).CHECK_EVENT() && typeid(*field.Get_Cell(x, y).Get_EVENT()) == typeid(Mine))
                std::cout << "@ ";
            else if (field.Get_Cell(x, y).CHECK_EVENT() && typeid(*field.Get_Cell(x, y).Get_EVENT()) == typeid(Teleport))
                std::cout << "0 ";
            else if (!field.Get_Cell(x, y).Get_State_of_cell())
                std::cout << "# ";
            else
                std::cout << ". ";
        }
        std::cout << std::endl;
    }
}

void Terminal_render::Print_game() const {
    //std::cout << "To move, use the keys: W - UP, S - DOWN, A - LEFT, D - RIGHT." << std::endl;
}

void Terminal_render::Print_new_game() const {
    std::cout<< "Do you want to restart the game ?(y - YES, n - NO)" <<std::endl;
}

void Terminal_render::Print_the_end() const {
    std::cout << "Thanks! Goodbye." << std::endl;
}

void Terminal_render::Clear() const {
    system("cls");
}
