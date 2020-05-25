//  Created by Eray Zesen on 25.05.2020.


#include "Game.hpp"
static Game* _game=nullptr;
Game::Game(){
    SDL_Init(SDL_INIT_VIDEO);
    
}
Game* Game::create(string projectName,int windowWidth,int windowHeight){
    if(!_game){
        _game=new Game();
    }
    
    _game->_projectName=projectName.c_str();
    _game->_windowWidth=windowWidth;
    _game->_windowHeight=windowHeight;
    
    return _game;
}
void Game::run(){
    _window = SDL_CreateWindow(_projectName,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, _windowWidth, _windowHeight, SDL_WINDOW_OPENGL);
    if(_window==NULL){
        printf("Could not create window: s%n",SDL_GetError());
    }
    SDL_Event e;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
        }
    }
}
