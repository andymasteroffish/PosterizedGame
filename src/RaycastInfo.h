#pragma once

#include "ofMain.h"

class GameObject;   //this let's us reference a pointer to Gameobject, even though GameObject includes this file


class RaycastInfo {
public:
    
    GameObject * hitObject;
    ofVec2f hitPoint;
    
    void clear(){
        hitObject = NULL;
        hitPoint.set(0,0);
    }
    
    
};