//  Created by Eray Zesen on 25.05.2020.


#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "SDL2/SDL.h"
using namespace std;

class Game{
public:
    static Game* create(string projectName, int windowWidth, int windowHeight);
    void run();
private:
    //properties
    Game();
    int _windowWidth=0;
    int _windowHeight=0;
    const char* _projectName;
    SDL_Window* _window;
    
};

#endif /* Game_hpp */
