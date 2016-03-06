#pragma once

#include "ofMain.h"
#include "PixelDotEffect.h"

class LaserChargeEffect : public PixelDotEffect {
	public:
    
    LaserChargeEffect();
	
    void setPosFromPlayer(ofVec2f playerPos);
    
    void applyEffectToDot(PixelDot (&dots)[DOTS_W][DOTS_H], ofVec2f scrollPos, float deltaTime);
    
    float rangeOfEffect;
    
};
