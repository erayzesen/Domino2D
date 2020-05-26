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
    
    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
    }
    
    return _game;
}

Game* Game::addNode(Sprite *node){
    SDL_Surface* srf= optimizeSurface(node->_image);
    SDL_BlitSurface(srf,NULL,_screenSurface,NULL);
    SDL_UpdateWindowSurface(_window);
    return this;
}
SDL_Surface* Game::getScreenSurface(){
    return _game->_screenSurface;
}
SDL_Surface* Game::optimizeSurface(SDL_Surface *rawSurface){
    SDL_Surface* optimizedSurface=SDL_ConvertSurface(rawSurface, _game->_screenSurface->format, 0);
    if( optimizedSurface == NULL )
    {
        printf( "Unable to optimize image! SDL Error: %s\n", SDL_GetError() );
    }

    return optimizedSurface;
}
void Game::run(){
    _window = SDL_CreateWindow(_projectName,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, _windowWidth, _windowHeight, SDL_WINDOW_OPENGL);
    if(_window==NULL){
        printf("Could not create window: s%n",SDL_GetError());
    }else{
        _screenSurface=SDL_GetWindowSurface(_window);
    }
    SDL_Event e;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
        }
        //Adding image to screen
        SDL_Surface* srf=IMG_Load("../Resources/supermario.png");
        SDL_Surface* optimized_srf=SDL_ConvertSurface(srf, _screenSurface->format,0);
        SDL_BlitSurface(optimized_srf,NULL,_screenSurface,NULL);
        SDL_UpdateWindowSurface(_window);
        //End Tutorial
        
    }
}
