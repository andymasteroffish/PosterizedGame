#pragma once

#include "ofMain.h"
#include "PixelDotEffect.h"

class HeartbeatEffect : public PixelDotEffect {
	public:
    
    HeartbeatEffect();
    
    void applyEffectToDot(PixelDot (&dots)[DOTS_W][DOTS_H], ofVec2f scrollPos, float deltaTime);
    
    
    //beating effect
    float timer;
    float curScale;
    
    
};
