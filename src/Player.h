#pragma once

#include "ofMain.h"
#include "GameObject.h"
#include "BasicInfo.h"
#include "HeartbeatEffect.h"
#include "LaserChargeEffect.h"
#include "LaserBlast.h"

class Player : public GameObject {
	public:
    
    void setupCustom();
    void updateCustom();
    void drawCustom();
    
    void keyPressed(int key);
    void keyReleased(int key);
    
    void startJump();
    
    float walkSpeed;
    int dir;
    
    bool holdingLeft, holdingRight;
    
    
    //heart effect
    HeartbeatEffect * heartbeatEffect;
    LaserChargeEffect * laserChargeEffect;
    
    //shooting
    bool isChargingShot;
    float shotChargeTimer;
    
    //drawing
    float drawW, drawH;
    
    //falling
    float grav;
    float yVel;
    bool isGrounded;
    
    float jumpPower;
    
    //figuring out when we are touching other objects
    ofVec2f groundRayStartOffset, groundRayEndOffset;
    
    //temporary animation test
    vector<ofImage> walkPics;
    float walkFrameTime, walkFrameTimer;
    int curWalkFrame;
    
    
};

