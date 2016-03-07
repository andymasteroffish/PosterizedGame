#include "LaserChargeEffect.h"

LaserChargeEffect::LaserChargeEffect(){
    setup();
    rangeOfEffect = 5;
    offsetFromParentObject.x = 20;
    offsetFromParentObject.y = -10;
}

void LaserChargeEffect::applyEffectToDot(PixelDot (&dots)[DOTS_W][DOTS_H], ofVec2f scrollPos, float deltaTime){
    
    //get the position of this dot
    GridPos centerDotPos = getDotPosFromGamePos(myGamePos, scrollPos);
    
    //some info
    float newPixelDotMoveXeno = 0.02;
    ofVec2f targetScreenPos;// = dots[centerDotPos.x, centerDotPos.y]->startScreenPos;
    targetScreenPos.x = centerDotPos.x*dots[centerDotPos.x, centerDotPos.y]->spacing;
    targetScreenPos.y = centerDotPos.y*dots[centerDotPos.x, centerDotPos.y]->spacing;
    
    //get all nearbydots
    int startX = MAX(0, centerDotPos.x-rangeOfEffect);
    int endX = MIN(DOTS_W-1, centerDotPos.x+rangeOfEffect);
    int startY = MAX(0, centerDotPos.y-rangeOfEffect);
    int endY = MIN(DOTS_H-1, centerDotPos.y+rangeOfEffect);
    
    for (int x=startX; x<=endX; x++){
        for (int y=startY; y<=endY; y++){
            dots[x][y].moveXeno = newPixelDotMoveXeno;
            dots[x][y].targetScreenPos = targetScreenPos;
        }
    }
}