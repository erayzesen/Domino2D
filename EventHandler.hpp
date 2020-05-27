//
//  EventHandler.hpp
//  Template_Domino2D_Project iOS
//
//  Created by Eray Zesen on 27.05.2020.
//  Copyright © 2020 Eray Zesen. All rights reserved.
//

#ifndef EventHandler_hpp
#define EventHandler_hpp

#include <stdio.h>
#include "SDL2/SDL.h"
#include "Scene.hpp"

class EventHandler{
public:
    EventHandler();
    static void init();
    static void checkAndApplyEvents(SDL_Event e,Node* node);
    static void applyUpdateEvents(Node* node);
};

#endif /* EventHandler_hpp */
