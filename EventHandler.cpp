//
//  EventHandler.cpp
//  Template_Domino2D_Project iOS
//
//  Created by Eray Zesen on 27.05.2020.
//  Copyright © 2020 Eray Zesen. All rights reserved.
//

#include "EventHandler.hpp"
static EventHandler* _eventHandler;
EventHandler::EventHandler(){
    
}
void EventHandler::init(){
    _eventHandler=new EventHandler();
}
void EventHandler::applyUpdateEvents(Node* node){
    map<string, Node*>::iterator itr;
    node->onUpdate();
    auto childs=node->getChilds();
    for(itr=childs.begin();itr!=childs.end();itr++){
        Node* child=itr->second;
        EventHandler::applyUpdateEvents(child);
    }
}
void EventHandler::checkAndApplyEvents(SDL_Event e,Node* node){
    switch (e.type) {
        case SDL_KEYDOWN:
            //Keydown Events
            break;
        case SDL_KEYUP:
            //KeyUp Events
            break;
        case SDL_MOUSEMOTION:
            //KeyUp Events
            break;
        case SDL_MOUSEBUTTONDOWN:
            //KeyUp Events
            break;
        case SDL_MOUSEBUTTONUP:
            //KeyUp Events
            break;
        case SDL_MOUSEWHEEL:
            //KeyUp Events
            break;
        case SDL_JOYBUTTONDOWN:
            //KeyUp Events
            break;
        case SDL_CONTROLLERBUTTONDOWN:
            //KeyUp Events
            break;
        case SDL_CONTROLLERBUTTONUP:
            //KeyUp Events
            break;
        case SDL_CONTROLLERAXISMOTION:
            //KeyUp Events
            break;
        case SDL_AUDIODEVICEADDED:
            //KeyUp Events
            break;
        case SDL_AUDIODEVICEREMOVED:
            //KeyUp Events
            break;
        case SDL_TEXTINPUT:
            //KeyUp Events
            break;
        case SDL_TEXTEDITING:
            //KeyUp Events
            break;
        default:
            break;
    }
}
