#include "BackgroundObject.h"


void BackgroundObject::setupCustom(){
    objectName = "bg circle";
    pos.set(ofRandom(-100, GAME_W+100), ofRandom(0, GAME_H));
    addCircleHitBox(30);
}

void BackgroundObject::drawCustom(){
    
    ofSetColor(180);
    
    ofCircle(pos.x, pos.y, 30);
    
}