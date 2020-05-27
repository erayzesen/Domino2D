//
//  Timer.hpp
//  Template_Domino2D_Project
//
//  Created by Eray Zesen on 27.05.2020.
//  Copyright © 2020 Eray Zesen. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

#include <stdio.h>
#include "SDL2/SDL.h"

class Timer{
public:
    Timer();
    static Timer* create();
    int getTicks();
    void start();
    void stop();
    void pause();
    void unpause();
private:
    int _startTicks=0;
    int _pausedTicks=0;
    bool _paused=false;
    bool _started=false;
};

#endif /* Timer_hpp */
