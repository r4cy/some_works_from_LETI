#ifndef GAME_H_
#define GAME_H_

#include <vector>

#include "interlayer.h"
#include "tracker.h"
#include "builder_field.h"
#include "log_of_file.h"
#include "log_of_terminal.h"

class Game {
private:
    Field field;
    Input_Interface& input;
    Interface_render& render;
    FieldCreator create_field;
    bool flag;
    std::vector<Logger*> logger;

    void Choose_logger(Interlayer& interlayer, Tracker& tracker);
    void Choose_lvl_of_map(Interlayer& interlayer, Tracker& tracker);
    void Play(Player& player, Interlayer& layer, Tracker& tracker);
    void The_end(Interlayer& layer, Tracker& tracker);

public:
    Game(Input_Interface& Value_input, Interface_render& Value_render);
    void Begin();
    ~Game();

};


#endif
