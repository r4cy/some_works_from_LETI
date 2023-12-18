#include "headers/game.h"
#include "headers/controller.h"

Game::Game(Input_Interface& Value_input, Interface_render& Value_render): input(Value_input), render(Value_render), flag(
        true) {}

void Game::Begin() {
    Player player;
    std::string filename = "D:\\LETI_works\\OOP_works_c++\\Works_from_LETI\\Garanin_Roman_OOP_lb1\\src\\control_keys";
    Interlayer layer(input, filename);
    Tracker tracker(render, layer, player, field);
    tracker.Checking_the_state(States_game::kSTART, logger);
    if(flag){
        Choose_logger(layer, tracker);
    }
    Choose_lvl_of_map(layer, tracker);
    Play(player, layer, tracker);
    The_end(layer, tracker);
}

void Game::Choose_logger(Interlayer &interlayer, Tracker &tracker) {
    tracker.Checking_the_state(States_game::kLOGGER, logger);
    flag = false;
    Action button;
    while(true){
        button = interlayer.Get_action();
        if(button == Action::kSAY_yes){
            while (true){
                tracker.Checking_the_state(States_game::kCHOOSE_LOGGER, logger);

                button = interlayer.Get_action();

                if(button == Action::kONE){
                    tracker.Checking_the_state(States_game::kKEY_COMMAND, logger);
                    logger.push_back(new Log_of_file);
                    break;
                }else if(button == Action::kTWO){
                    tracker.Checking_the_state(States_game::kKEY_COMMAND, logger);
                    logger.push_back(new Log_of_terminal);
                    break;
                }else if(button == Action::kTHREE){
                    tracker.Checking_the_state(States_game::kKEY_COMMAND, logger);
                    logger.push_back(new Log_of_terminal);
                    logger.push_back(new Log_of_file);
                    break;
                }
                tracker.Checking_the_state(States_game::kKEY, logger);
            }
            break;
        }else if(button == Action::kSAY_no){
            if(!logger.empty()){
                for(int i = 0; i < logger.size(); i++){
                    delete logger[i];
                    logger[i] = nullptr;
                }
            }
            break;
        }
    }
}

void Game::Choose_lvl_of_map(Interlayer& interlayer, Tracker& tracker) {
    Action button;
    while (true){
        tracker.Checking_the_state(States_game::kLEVEL, logger);
        button = interlayer.Get_action();

        if(button == Action::kONE){
            tracker.Checking_the_state(States_game::kKEY_COMMAND, logger);
            field = create_field.Create_of_lvl1();
            break;
        }else if(button == Action::kTWO){
            tracker.Checking_the_state(States_game::kKEY_COMMAND, logger);
            field = create_field.Create_of_lvl2();
            break;
        }
        tracker.Checking_the_state(States_game::kKEY, logger);
    }
}

void Game::Play(Player& player, Interlayer& layer, Tracker& tracker) {
    tracker.Checking_the_state(States_game::kGAME, logger);
    Controller contr(player, field);
    Action button;
    Joystick joystick;

    do{
        tracker.Checking_the_state(States_game::kPLAY, logger);
        if(player.Get_Health() <= 0){
            tracker.Checking_the_state(States_game::kLOOSE, logger);
            break;
        }

        if(player.Get_X() == field.Get_Exit_X() && player.Get_Y() == field.Get_Exit_Y()){
            tracker.Checking_the_state(States_game::kWIN, logger);
            break;
        }

        button = layer.Get_action();

        switch (button) {
            case Action::kMOVE_up:
                tracker.Checking_the_state(States_game::kKEY_COMMAND, logger);
                joystick = Joystick::kUP;
                break;
            case Action::kMOVE_left:
                tracker.Checking_the_state(States_game::kKEY_COMMAND, logger);
                joystick = Joystick::kLEFT;
                break;
            case Action::kMOVE_down:
                tracker.Checking_the_state(States_game::kKEY_COMMAND, logger);
                joystick = Joystick::kDOWN;
                break;
            case Action::kMOVE_right:
                tracker.Checking_the_state(States_game::kKEY_COMMAND, logger);
                joystick = Joystick::kRIGHT;
                break;
            case Action::kGO_quit:
                tracker.Checking_the_state(States_game::kKEY_COMMAND, logger);
                break;
            default:
                tracker.Checking_the_state(States_game::kKEY, logger);
                continue;
        }
        contr.Walking(joystick);
    } while (button != Action::kGO_quit);
}

void Game::The_end(Interlayer& layer, Tracker& tracker) {
    Action button;
    while (true){
        tracker.Checking_the_state(States_game::kNEW, logger);
        button = layer.Get_action();

        if(button == Action::kSAY_yes){
            tracker.Checking_the_state(States_game::kKEY_COMMAND, logger);
            Begin();
            break;
        }else if(button == Action::kSAY_no){
            tracker.Checking_the_state(States_game::kKEY_COMMAND, logger);
            tracker.Checking_the_state(States_game::kEND, logger);
            exit(0);
        }
        tracker.Checking_the_state(States_game::kKEY, logger);
    }
}

Game::~Game() {
    if (!logger.empty()){
        for(int i = 0; i < logger.size(); i++){
            delete logger[i];
        }
        logger.clear();
    }
}
