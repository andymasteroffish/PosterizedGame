#include "Player.h"


void Player::setupCustom(){
    walkSpeed = 0.34;
    
    holdingLeft = false;
    holdingRight = false;
    
    pos.x = GAME_W / 2;
    pos.y = GAME_H / 2;
    
    heartbeatEffect = new HeartbeatEffect();
    pixelEffects.push_back(heartbeatEffect);
    
}

void Player::updateCustom(){
    
    if (holdingLeft){
        pos.x -= walkSpeed;
    }
    if (holdingRight){
        pos.x += walkSpeed;
    }
    
    heartbeatEffect->setPosFromPlayer(pos);
    
    
}

void Player::drawCustom(){
    
    ofSetColor(0, 0, 0);
    
    ofRect(pos.x, pos.y, 40, 80);
    
    //tetsing
    //ofSetColor(255,0,0);
    //ofCircle(heartPos.x, heartPos.y, 3);
    
}

void Player::keyPressed(int key){
    if (key == 356)  holdingLeft = true;
    if (key == 358) holdingRight = true;
    
}
void Player::keyReleased(int key){
    if (key == 356)  holdingLeft = false;
    if (key == 358) holdingRight = false;
}