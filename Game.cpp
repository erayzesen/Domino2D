//  Created by Eray Zesen on 25.05.2020.


#include "Game.hpp"
static Game* _game=nullptr;
Game::Game(){
    SDL_Init(SDL_INIT_VIDEO);
    _timer=Timer::create();
    _timer->start();
    
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



SDL_Surface* Game::getScreenSurface(){
    return _game->_screenSurface;
}

Scene* Game::getCurrentScene(){
    //Returns Current Scene Node
    return _game->_scene;
}

void Game::runWithScene(Scene* scene){
    //Creating Window
    _window = SDL_CreateWindow(_projectName,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, _windowWidth, _windowHeight, SDL_WINDOW_OPENGL);
    if(_window==NULL){
        printf("Could not create window: s%n",SDL_GetError());
    }else{
        //Initializing Renderer
        Renderer::init(_window);
        //Initializing EventHandler
        EventHandler::init();
        //Setting Surface of The Window
        _screenSurface=SDL_GetWindowSurface(_window);
    }
    SDL_Event e;
    bool quit = false;
    while (!quit){
        //Increment the frame counter
        _currentFrame++;
        if(_currentFrame<1)continue;
        
        EventHandler::checkAndApplyEvents(e,scene);
        //Calling Update Events
        EventHandler::applyUpdateEvents(scene);
        SDL_Delay((1000/_fps));
        
        //Clear Renderer
        SDL_RenderClear(Renderer::getRenderer());
        //Updating Renderer
        Renderer::update(scene);
        //Update Screen
        SDL_RenderPresent(Renderer::getRenderer());
        while (SDL_PollEvent(&e)){
            
            if (e.type == SDL_QUIT){
                quit = true;
            }
        }
        
        
        
    }
}
bool Game::isTimeToFrame(){
    
    return true;
}
Game* Game::setFPS(int frameRate){
    _game->_fps=frameRate;
    return _game;
}
