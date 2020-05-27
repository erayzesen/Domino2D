//
//  Node.hpp
//  Template_Domino2D_Project
//
//  Created by Eray Zesen on 27.05.2020.
//  Copyright © 2020 Eray Zesen. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

class Node{
public:
    Node();
    static Node* create(string name);
    Node *addChild(Node* node);
    map<string, Node*> getChilds();
    string getName();
    Node* setName(string name);

    //Transform Properties Settings
    Node* setPos(int x,int y);
    Node* setPosX(int x);
    Node* setPosY(int y);
    Node* setVisible(bool trueOrFalse);
    //Transform Properties Gettings
    pair<int,int> getPos();
    int getPosX();
    int getPosY();
    bool getVisible();
    
    //Child Functions
    Node * getChild(string name);
    Node * setParent(Node* node);
    Node * getParent();
    Node * removeChild(Node* node,bool permanently=true);
    void remove();
    
    //Events
    virtual void onUpdate();
protected:
private:
    string _name;
    map <string,Node*> _childs;
    //Properties
    Node* _parent=NULL;
    int _x=0;
    int _y=0;
    bool _visible=true;
    //Event Back Variables
    
};

#endif /* Node_hpp */
