#ifndef GAME_H_
#define GAME_H_

#include "interlayer.h"
#include "tracker.h"
#include "builder_field.h"

class Game {
private:
    Field field;
    Input_Interface& input;
    Interface_render& render;
    FieldCreator create_field;

    void Choose_lvl_of_map(Tracker& tracker);
    void Play(Player& player, Interlayer& layer, Tracker& tracker);
    int The_end(Interlayer& layer, Tracker& tracker);

public:
    Game(Input_Interface& Value_input, Interface_render& Value_render);
    void Begin();


};


#endif
