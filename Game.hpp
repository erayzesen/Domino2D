//  Created by Eray Zesen on 25.05.2020.


#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "SDL2/SDL.h"
#include "Sprite.hpp"
#include "Renderer.hpp"
#include "Scene.hpp"
#include "EventHandler.hpp"
#include "Timer.hpp"

using namespace std;

class Game{
public:
    static Game* create(string projectName, int windowWidth, int windowHeight);
    void runWithScene(Scene* scene);
    static SDL_Surface* getScreenSurface();
    static Scene* getCurrentScene();
    static Game* setFPS(int frameRate);
    Game();
private:
    //properties
    bool isTimeToFrame();
    int _windowWidth=0;
    int _windowHeight=0;
    const char* _projectName;
    SDL_Window* _window;
    SDL_Surface* _screenSurface;
    SDL_Renderer* _renderer;
    Scene* _scene;
    Timer* _timer;
    int _currentFrame;
    int _fps=60;
    
};

#endif /* Game_hpp */
