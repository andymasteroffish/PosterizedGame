#include "BackgroundObject.h"


void BackgroundObject::setupCustom(){
    pos.set(ofRandom(-100, GAME_W+100), ofRandom(0, GAME_H));
}

void BackgroundObject::drawCustom(){
    
    ofSetColor(180);
    
    ofCircle(pos.x, pos.y, 30);
    
}