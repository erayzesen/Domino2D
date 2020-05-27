//
//  Node.cpp
//  Template_Domino2D_Project
//
//  Created by Eray Zesen on 27.05.2020.
//  Copyright © 2020 Eray Zesen. All rights reserved.
//

#include "Node.hpp"

Node::Node(){
    //Event Operations
}
Node* Node::create(string name){
    //Creating new Node
    Node* nNode=new Node();
    //Setting name
    nNode->setName(name);
    return nNode;
}

Node * Node::addChild(Node *node){
    //Adding child to the _childs container
    _childs.insert(make_pair(node->_name,node));
    node->_parent=this;
    return node;
}
map<string,Node*> Node::getChilds(){
    //Giving Childs
    return _childs;
}

string Node::getName(){
    //Giving Name
    return _name;
}
Node* Node::setName(string name){
    //Giving Name
    _name=name;
    return this;
}
//SETTING TRANSFORM PROPERTIES
Node* Node::setPos(int x,int y){
    //Setting x and y positions
    _x=x;
    _y=y;
    return this;
}
Node* Node::setPosX(int x){
    //Setting the x position
    _x=x;
    return this;
}
Node* Node::setPosY(int y){
    //Setting the y position
    _y=y;
    return this;
}
Node* Node::setVisible(bool trueOrFalse){
    //Setting the visibility
    _visible=trueOrFalse;
    return this;
}
//GETTING TRANSFORM PROPERTIES
pair<int,int> Node::getPos(){
    //Giving x and y positions
    pair<int,int> pos;
    pos.first=_x;
    pos.second=_y;
    return pos;
}
int Node::getPosX(){
    //Giving the x position
    return _x;
}
int Node::getPosY(){
    //Giving the y position
    return _y;
}
bool Node::getVisible(){
    //Giving the visibility
    return _visible;
}
//CHILD FUNCTIONS
Node * Node::setParent(Node *node){
    node->addChild(this);
    return this;
}
Node * Node::getParent(){
    return _parent;
}
Node * Node::getChild(string name){
    map<string,Node*>::iterator it;
    Node * childNode=NULL;
    //Finding Child
    it=_childs.find(name);
    if(it==_childs.end()){
        printf("Can't find %s named child in %s named node! \n",name.c_str(),_name.c_str());
    }else{
        //Giving the Child
        childNode=it->second;
    }
    
    return childNode;
}
Node * Node::removeChild(Node *node,bool permanently){
    Node* nodeParent=node->getParent();
    //Checking The Parent
    if(nodeParent!=NULL){
        map<string,Node*>::iterator it;
        //Finding Child
        it=nodeParent->getChilds().find(node->getName());
        //Deleting from Parent Childs
        if(it!=nodeParent->getChilds().end())nodeParent->getChilds().erase(it);
        //Setting Visible Value false
        node->setVisible(false);
    }
    if(permanently==true)node->remove();
    return this;
}
void Node::remove(){
    //Permanently Removing Operations Will Come Here
}
void Node::onUpdate(){
    //It's Empty and Virtual Function
}
