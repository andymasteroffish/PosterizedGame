#pragma once

#include "ofMain.h"
#include "GameObject.h"
#include "Bullet.h"

class Turret : public GameObject {
	public:
    
    Turret(float startX, float startY);
    
    void setupCustom();
    void updateCustom();
    void drawCustom();
    void shoot();
    
    float drawH, drawW;
    
    GameObject * player;
    float rangeToShootPlayer;
    
    float timeBetweenShots;
    float shotTimer;
    
    
    
};

