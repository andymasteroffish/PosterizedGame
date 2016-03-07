#include "Player.h"


void Player::setupCustom(){
    walkSpeed = 0.34;
    
    setHitBox(40, 80);
    
    holdingLeft = false;
    holdingRight = false;
    dir = 1;
    
    pos.x = GAME_W * 0.5;
    pos.y = GAME_H * 0.75;
    
    heartbeatEffect = new HeartbeatEffect();
    pixelEffects.push_back(heartbeatEffect);
    
    laserChargeEffect = new LaserChargeEffect();
    laserChargeEffect->isActive = false;
    pixelEffects.push_back(laserChargeEffect);
    
    isChargingShot = false;
    shotChargeTimer = 0;
    
}

void Player::updateCustom(){
    
    if (holdingLeft){
        pos.x -= walkSpeed;
        dir = -1;
    }
    if (holdingRight){
        pos.x += walkSpeed;
        dir = 1;
    }
    
    if (isChargingShot){
        //cout<<"timer "<<shotChargeTimer<<endl;
        shotChargeTimer += deltaTime;
    }
    
    
}

void Player::drawCustom(){
    
    ofSetColor(0, 0, 0);
    
    ofRect(pos.x+hitBox.x, pos.y+hitBox.y, hitBox.width, hitBox.height);
    
    //tetsing
    //ofSetColor(255,0,0);
    //ofCircle(heartPos.x, heartPos.y, 3);
    
}

void Player::keyPressed(int key){
    if (key == 356)  holdingLeft = true;
    if (key == 358) holdingRight = true;
    
    if (key == ' ' && !isChargingShot){
        isChargingShot = true;
        laserChargeEffect->isActive = true;
        shotChargeTimer = 0;
    }
    
}
void Player::keyReleased(int key){
    if (key == 356)  holdingLeft = false;
    if (key == 358) holdingRight = false;
    
    if (key == ' '){
        isChargingShot = false;
        laserChargeEffect->isActive = false;
        LaserBlast * newBlast = new LaserBlast();
        newBlast->setFromShooter(pos, dir, shotChargeTimer);
        gameObjectToAdd = newBlast;
    }
}