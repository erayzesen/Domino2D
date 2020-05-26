//
//  Sprite.cpp
//  Template_Domino2D_Project
//
//  Created by Eray Zesen on 26.05.2020.
//  Copyright © 2020 Eray Zesen. All rights reserved.
//

#include "Sprite.hpp"
Sprite::Sprite(){
    
}
Sprite* Sprite::create(string filePath){
    Sprite* sprite=new Sprite();
    sprite->loadImage(filePath.c_str());
    return sprite;
}
bool Sprite::loadImage(const char* fp){
    _image=IMG_Load(fp);
    if(_image==NULL){
        printf("Unable to load image %s! SDL Error: %s\n",fp,SDL_GetError());
        return false;
    }else{
        //_image=SDL_ConvertSurface(loadedSurface,Game::getScreenSurface()->format, 0)
        
    }
    return true;
}
