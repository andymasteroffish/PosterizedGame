#pragma once

#include "ofMain.h"
#include "GameObject.h"




class RaycastInfo {
public:
    
    
    int hitObjectID;    //CHANGE THIS TO A REFERENCE TO THE ACTUAL OBJECT
    ofVec2f hitPoint;
    
    GameObjectLayer hitObjectLayer;
    
    void clear(){
        hitObjectID = -1;
        hitPoint.set(0,0);
        hitObjectLayer = LAYER_DEFAULT;
    }
    
    
};