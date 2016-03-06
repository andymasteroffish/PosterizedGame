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
    
    float walkSpeed;
    int dir;
    
    bool holdingLeft, holdingRight;
    
    
    //heart effect
    HeartbeatEffect * heartbeatEffect;
    LaserChargeEffect * laserChargeEffect;
    
    //shooting
    bool isChargingShot;
    float shotChargeTimer;
    
    
    
};

