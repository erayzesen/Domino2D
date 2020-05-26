//
//  Sprite.hpp
//  Template_Domino2D_Project
//
//  Created by Eray Zesen on 26.05.2020.
//  Copyright © 2020 Eray Zesen. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include <stdio.h>
#include <iostream>
using namespace std;
class Sprite{
public:
    Sprite();
    static Sprite* create(string filePath);
    SDL_Surface* _image;
private:
    char* _filePath;
    bool loadImage(const char* fp);
    //SDL_Surface* loadSurface(string path);
};

#endif /* Sprite_hpp */
