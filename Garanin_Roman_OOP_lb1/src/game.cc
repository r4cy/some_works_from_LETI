#include "game.h"
Game::Game(Interlayer &Value_layer): layer(Value_layer) {}

void Game::Begin() {
    std::cout << "Hello and Welcome in my Game!" << std::endl;
    Choose_lvl_of_map();
    Play();
    The_end();
}

void Game::Choose_lvl_of_map() {
    while (true){
        int LVL;

        std::cout << "Choose a level of map (1 or 2):" << std::endl;
        std::cin >> LVL;

        if(LVL == 1){
            field = create_field.Create_of_lvl1();
            break;
        }else if(LVL == 2){
            field = create_field.Create_of_lvl2();
            break;
        }else{
            std::cout << "Wrong level, try again!" << std::endl;
            continue;
        }
    }
}

void Game::Play() {
    Player player;
    Controller contr(player, field);
    Action button;
    Joystick joystick;

    while(true){
        player.PRINT_VALUES();
        field.PRINT_FIELD(player);

        if(player.Get_Health() <= 0){
            std::cout << "You're dead!" <<std::endl;
            break;
        }

        if(player.Get_X() == field.Get_Exit_X() && player.Get_Y() == field.Get_Exit_Y()){
            std::cout << "Congratulations, you have reached the finish line!" << std::endl;
            break;
        }

        std::cout << "To move, use the keys: W - UP, S - DOWN, A - LEFT, D - RIGHT." << std::endl;
        button = layer.Get_action();

        if (button == Action::kGO_quit)
            break;

        switch (button) {
            case Action::kMOVE_up:
                joystick = Joystick::kUP;
                break;
            case Action::kMOVE_left:
                joystick = Joystick::kLEFT;
                break;
            case Action::kMOVE_down:
                joystick = Joystick::kDOWN;
                break;
            case Action::kMOVE_right:
                joystick = Joystick::kRIGHT;
                break;
            default:
                continue;
        }
        contr.Walking(joystick);
        system("cls");
    }
}

void Game::The_end() {
    Action action;

    while (true){
        std::cout<< "Do you want to restart the game ?(SEND: Y - YES/N - NO)" <<std::endl;
        action = layer.Get_action();

        if(action == Action::kSAY_yes){
            Begin();
        }else if(action == Action::kSAY_no){
            exit(0);
        }else{
            continue;
        }
        system("cls");
    }
}
