#pragma once

#include "ofMain.h"
#include "PixelDotEffect.h"

class GameObject {
	public:
	
    void setup();
    virtual void setupCustom() {}
    
    void update(float _deltaTime);
    virtual void updateCustom() {}
    
    void draw();
    virtual void drawCustom() {}
    
    void destroy();
    virtual void destroyCustom(){}
    
    void addMyPixelEffectsToVector(vector<PixelDotEffect*> * targetVector);
    
    
    float deltaTime;
    
    vector<PixelDotEffect *> pixelEffects;
    
    
};
