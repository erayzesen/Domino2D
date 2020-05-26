//  Created by Eray Zesen on 25.05.2020.


#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "SDL2/SDL.h"
#include "Sprite.hpp"
using namespace std;

class Game{
public:
    static Game* create(string projectName, int windowWidth, int windowHeight);
    void run();
    Game* addNode(Sprite* node);
    static SDL_Surface* getScreenSurface();
    Game();
private:
    //properties
    int _windowWidth=0;
    int _windowHeight=0;
    const char* _projectName;
    SDL_Window* _window;
    SDL_Surface* _screenSurface;
    SDL_Surface* optimizeSurface(SDL_Surface *rawSurface);
    
};

#endif /* Game_hpp */
