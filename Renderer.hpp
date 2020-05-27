//
//  Renderer.hpp
//  Template_Domino2D_Project
//
//  Created by Eray Zesen on 27.05.2020.
//  Copyright © 2020 Eray Zesen. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include <stdio.h>
#include "SDL2/SDL.h"
#include "Scene.hpp"
#include "Sprite.hpp"

class Renderer{
public:
    Renderer();
    static SDL_Renderer* getRenderer();
    static SDL_Renderer* init(SDL_Window* window);
    static void update(Scene * scene);
    
private:
    static void updateNodeRenderParts(Node* node,int xPos,int yPos);

};

#endif /* Renderer_hpp */
