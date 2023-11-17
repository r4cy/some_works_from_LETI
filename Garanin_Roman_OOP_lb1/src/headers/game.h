#ifndef GAME_H_
#define GAME_H_

#include "interlayer.h"
#include "builder_field.h"
#include "controller.h"

class Game {
private:
    Field field;
    Interlayer& layer;
    FieldCreator create_field;

    void Choose_lvl_of_map();
    void Play();
    void The_end();

public:
    Game(Interlayer& Value_layer);
    void Begin();


};


#endif
