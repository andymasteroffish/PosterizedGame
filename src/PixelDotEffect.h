#pragma once

#include "ofMain.h"
#include "BasicInfo.h"
#include "PixelDot.h"

class PixelDotEffect {
	public:
	
    
    
    virtual void applyEffectToDot(PixelDot (&dots)[DOTS_W][DOTS_H], ofVec2f scrollPos, float deltaTime){}
    
    GridPos getDotPosFromGamePos(ofVec2f gamePos, ofVec2f scrollPos);
    PixelDot * getPixelDotFromGamePos(PixelDot (&dots)[DOTS_W][DOTS_H], ofVec2f gamePos, ofVec2f scrollPos);
    
    
    ofVec2f myGamePos;
    
    
};
