#include "PixelDotEffect.h"

void PixelDotEffect::setup(){
    isActive = true;
}


void PixelDotEffect::setPosFromParentObject(ofVec2f objectPos){
    myGamePos = objectPos + offsetFromParentObject;
}

GridPos PixelDotEffect::getDotPosFromGamePos(ofVec2f gamePos, ofVec2f scrollPos){
    GridPos dotPos;
    
    float gameToDotsConversion = GAME_W / DOTS_W;
    
    ofVec2f posAfterScroll = gamePos + scrollPos;
    
    dotPos.x = posAfterScroll.x / gameToDotsConversion;
    dotPos.y = posAfterScroll.y / gameToDotsConversion;
    
    return dotPos;
}


PixelDot * PixelDotEffect::getPixelDotFromGamePos(PixelDot (&dots)[DOTS_W][DOTS_H], ofVec2f gamePos, ofVec2f scrollPos){
    GridPos dotPos = getDotPosFromGamePos(gamePos, scrollPos);
    if (dotPos.x < 0 || dotPos.x >= DOTS_W || dotPos.y < 0 || dotPos.y >= DOTS_H){
        cout<<"DOT OUT OF RANGE"<<endl;
        return NULL;
    }
    
    return &dots[dotPos.x][dotPos.y];
    
}