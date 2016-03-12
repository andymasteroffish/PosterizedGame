#pragma once

#include "ofMain.h"
#include "GameObject.h"
#include "BasicInfo.h"

class LaserBlast : public GameObject {
	public:
		
    void setupCustom();
    void setFromShooter(ofVec2f _pos, int _dir, float chargeTime);
    void updateCustom();
    void drawCustom();
    
    
    int dir;
    
    float heightPerChargeSecond;
    float maxStartHeight;
    float startHeight;
    
    float curHeight;
    float width;
    
    float timeBeforeDeath;
    float timer;
    float timingCurve;
    
    ofVec2f startPos;
    
    bool hasDoneHitCheck;
};
