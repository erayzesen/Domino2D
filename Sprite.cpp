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
Sprite* Sprite::create(string name,string filePath){
    Sprite* sprite=new Sprite();
    //Setting Name
    sprite->setName(name);
    //Setting Image File Path
    sprite->_filePath=filePath.c_str();
    //Loading Image
    sprite->_image=IMG_Load(filePath.c_str());
    //Checking Image File
    if(sprite->_image==NULL){
        printf("Unable to load Texture %s! SDL Error: %s\n",filePath.c_str(),SDL_GetError());
    }
    return sprite;
}
bool Sprite::initTexture(){
    //Checking "_image" Variable & Renderer
    if(_image==NULL){
        printf("Sprite image has not been loaded! \n");
        return false;
    }else if(Renderer::getRenderer()==NULL){
        printf("Renderer has not been initialized! \n");
        return false;
    }
    //Creating a Texture from the Image
    _texture=SDL_CreateTextureFromSurface(Renderer::getRenderer(), _image);
    if(_texture==NULL){
        printf( "Unable to create texture from %s!(Sprite::loadTexture) SDL Error: %s\n", _filePath, SDL_GetError() );
        return false;
    }
    return true;
}
SDL_Texture* Sprite::getTexture(){
    //Checking Texture, If It's not Initialize, Initializing.
    if(_texture==NULL){
        initTexture();
    }
    //Giving a Texture
    return _texture;
}
string Sprite::getFilePath(){
    //Giving a FilePath
    return _filePath;
}
