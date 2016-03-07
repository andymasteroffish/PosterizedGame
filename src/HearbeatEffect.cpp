#include "HeartbeatEffect.h"

HeartbeatEffect::HeartbeatEffect(){
    setup();
    offsetFromParentObject.x = -10;
    offsetFromParentObject.y = 0;
    timer = 99999;
    curScale = 1;
}



void HeartbeatEffect::applyEffectToDot(PixelDot (&dots)[DOTS_W][DOTS_H], ofVec2f scrollPos, float deltaTime){
    //get the dot
    PixelDot * thisDot = getPixelDotFromGamePos(dots, myGamePos, scrollPos);
    
    //set the color to red
    thisDot->col.set(255, 0, 0);
    
    //modify the effect scale to make a heartbeat
    timer += deltaTime;
    
    float totalTime = 1.25;
    float middlebeat = totalTime * 0.6;
    
    
    float maxScale = 2;
    float minScale = 1;
    float scaleDropPerSecond = 1;
    
    curScale -= scaleDropPerSecond * deltaTime;
    curScale = MAX(curScale, minScale);
    
    if (timer >= totalTime){
        timer = 0;
        curScale = maxScale;
    }
    if (timer-deltaTime < middlebeat && timer >= middlebeat){
        curScale = maxScale;
    }
    
    thisDot->effectScale = curScale;
}