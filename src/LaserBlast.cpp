#include "LaserBlast.h"


void LaserBlast::setupCustom(){
    timer = 0;
    timeBeforeDeath = 0.3;
    timingCurve = 2;
    
    width = GAME_W*0.75;
    
    zIndex = -1;
}

void LaserBlast::setFromShooter(ofVec2f _pos, int _dir, float chargeTime){
    dir = _dir;
    pos = _pos;
    pos.y += 17;    //move it down a bit
    pos.x += 20;
    
    startPos = pos;
    
    heightPerChargeSecond = 20;
    maxStartHeight = 40;
    
    startHeight = chargeTime * heightPerChargeSecond;
    startHeight = MIN(startHeight, maxStartHeight);
    curHeight = startHeight;
    
    //cout<<"laser charge "<<chargeTime<<"  height "<<startHeight<<endl;
    
}

void LaserBlast::updateCustom(){
    timer += deltaTime;
    
    float prc = 1-(timer/timeBeforeDeath);
    prc = CLAMP(prc, 0, 1);
    prc = powf(prc, timingCurve);
    
    curHeight = startHeight*prc;
    
    pos.y = startPos.y - curHeight * 0.5;
    if (prc <= 0){
        killMe = true;
    }
}

void LaserBlast::drawCustom(){
    
    ofSetColor(0);
    
    ofRect(pos.x, pos.y, width*dir, curHeight);
    //cout<<"draw laser"<<endl;
    
    
}