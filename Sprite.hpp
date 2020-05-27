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
#include "Node.hpp"
#include "Renderer.hpp"

using namespace std;
class Sprite : public Node{
public:
    Sprite();
    static Sprite* create(string name,string filePath);
    SDL_Texture* getTexture();
    string getFilePath();
private:
    const char* _filePath;
    bool initTexture();
    SDL_Surface* _image=NULL;
    SDL_Texture* _texture=NULL;
    //SDL_Surface* loadSurface(string path);
};

#endif /* Sprite_hpp */
