//
//  Renderer.cpp
//  Template_Domino2D_Project
//
//  Created by Eray Zesen on 27.05.2020.
//  Copyright © 2020 Eray Zesen. All rights reserved.
//

#include "Renderer.hpp"
static SDL_Renderer* _renderer;
Renderer::Renderer(){
    
}
SDL_Renderer * Renderer::getRenderer(){
    if(_renderer==NULL){
        printf("Renderer has not initialized! \n");
    }
    return _renderer;
}
SDL_Renderer * Renderer::init(SDL_Window* window){
    //Creating Renderer
    _renderer=SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);
    if(_renderer==NULL){
        printf( "Renderer could not be created!(Game::run()) SDL Error: %s\n", SDL_GetError() );
    }else{
        //Setting renderer
        //Rendering Background
        SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0x00);
    }
    return _renderer;
}


void Renderer::update(Scene* scene){
    //getting all of childs
    auto childs=scene->getChilds();
    map<string, Node*>::iterator itr;
     Renderer::updateNodeRenderParts(scene,scene->getPosX(),scene->getPosY());
}

void Renderer::updateNodeRenderParts(Node* node, int xPos, int yPos){
    
    //Checking is Renderer Initialized
    if(Renderer::getRenderer()==NULL){
        return;
    }
    //Getting Childs of the Node
    map<string, Node*>::iterator itr;
    auto childs=node->getChilds();
    for(itr=childs.begin();itr!=childs.end();itr++){
        //Trying Node Type to Sprite Type
        Sprite* sprite=static_cast<Sprite*>(itr->second);
        //Checking Is Node a Sprite
        if(sprite!=NULL){
            //Getting Texture from Sprite
            SDL_Texture* texture=sprite->getTexture();
            //Checking Sprite Texture
            if(texture!=NULL){
                //Rect variables
                int x,y,w,h;
                //Getting Texture Width and Height
                SDL_QueryTexture(texture, NULL,NULL,&w,&h);
                //Getting Relative Position of the Node:  Parent Child Relative Position + Node Position
                x=xPos+sprite->getPosX();
                y=yPos+sprite->getPosY();
                //Creating Rect to Rendering
                SDL_Rect sRect={x,y,w,h};
                //Rendering Texture
                SDL_RenderCopy(Renderer::getRenderer(),texture,NULL,&sRect);
                 
                 
            }else{
                printf("Texture Error!(Renderer::update()) Sprite name is %s and image path is %s .\n ",sprite->getName().c_str(),sprite->getFilePath().c_str());
            }
        }
        Renderer::updateNodeRenderParts(itr->second,itr->second->getPosX(),itr->second->getPosY());
        
    }
}
