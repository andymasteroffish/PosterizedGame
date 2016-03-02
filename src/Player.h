#pragma once

#include "ofMain.h"
#include "GameObject.h"
#include "BasicInfo.h"
#include "HeartbeatEffect.h"

class Player : public GameObject {
	public:
    
    void setupCustom();
    void updateCustom();
    void drawCustom();
    
    void keyPressed(int key);
    void keyReleased(int key);
    
    float walkSpeed;
    
    bool holdingLeft, holdingRight;
    
    ofVec2f pos;
    
    
    //heart effect
    HeartbeatEffect * heartbeatEffect;
    
    
    
};

