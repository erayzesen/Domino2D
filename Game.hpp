//
//  Game.hpp
//  Template_Domino2D_Project
//
//  Created by Eray Zesen on 25.05.2020.
//  Copyright © 2020 Eray Zesen. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "SDL2/SDL.h"

class Game{
public:
    Game();
    Game* create();
    Game* setSize();
    Game* run();
private:
    //properties
    int width=0;
    int height=0;
    
    
};

#endif /* Game_hpp */
