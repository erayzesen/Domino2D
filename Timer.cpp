//
//  Timer.cpp
//  Template_Domino2D_Project
//
//  Created by Eray Zesen on 27.05.2020.
//  Copyright © 2020 Eray Zesen. All rights reserved.
//

#include "Timer.hpp"

Timer::Timer(){
    
}
Timer* Timer::create(){
    Timer* ntimer=new Timer();
    return ntimer;
}
int Timer::getTicks(){
    if(_started==true){
        if(_paused==true){
            return _pausedTicks;
        }else{
            return SDL_GetTicks()-_startTicks;
        }
    }
    return 0;
}
void Timer::start(){
    //Start the timer
    _started=true;
    //Unpause the timer
    _paused=false;
    //Get the current clock time
    _startTicks=SDL_GetTicks();
}
void Timer::stop(){
    //Start the timer
    _started=false;
    //Unpause the timer
    _paused=false;
}
void Timer::pause(){
    //If the timer is running and isn't already paused
    if( ( _started == true ) && ( _paused == false ) )
    {
        //Pause the timer
        _paused = true;

        //Calculate the paused ticks
        _pausedTicks = SDL_GetTicks() - _startTicks;
    }
}
void Timer::unpause(){
    //If the timer is paused
    if( _paused == true )
    {
        //Unpause the timer
        _paused = false;

        //Reset the starting ticks
        _startTicks = SDL_GetTicks() - _pausedTicks;

        //Reset the paused ticks
        _pausedTicks = 0;
    }
}
