#include "headers/game.h"
#include "headers/controller.h"

Game::Game(Input_Interface& Value_input, Interface_render& Value_render): input(Value_input), render(Value_render) {}

void Game::Begin() {
    Player player;
    std::string filename = "D:\\LETI_works\\OOP_works_c++\\Works_from_LETI\\Garanin_Roman_OOP_lb1\\src\\control_keys";
    Interlayer layer(input, filename);
    Tracker tracker(render, player, field);
    tracker.Checking_the_state(States_game::kSTART);
    Choose_lvl_of_map(tracker);
    Play(player, layer, tracker);
    The_end(layer, tracker);
}

void Game::Choose_lvl_of_map(Tracker& tracker) {
    tracker.Checking_the_state(States_game::kLEVEL);
    while (true){
        int LVL;

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

void Game::Play(Player& player, Interlayer& layer, Tracker& tracker) {
    Controller contr(player, field);
    Action button;
    Joystick joystick;

    do{
        tracker.Checking_the_state(States_game::kPLAY);
        if(player.Get_Health() <= 0){
            tracker.Checking_the_state(States_game::kLOOSE);
            break;
        }

        if(player.Get_X() == field.Get_Exit_X() && player.Get_Y() == field.Get_Exit_Y()){
            tracker.Checking_the_state(States_game::kWIN);
            break;
        }

        button = layer.Get_action();

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
    } while (button != Action::kGO_quit);
}

void Game::The_end(Interlayer& layer, Tracker& tracker) {
    Action button;
    tracker.Checking_the_state(States_game::kNEW);
    while (true){
        button = layer.Get_action();

        if(button == Action::kSAY_yes){
            Begin();
        }else if(button == Action::kSAY_no){
            tracker.Checking_the_state(States_game::kEND);
            exit(0);
        }else{
            continue;
        }
    }
}
