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
    
    ofVec2f pos;
    
    vector<PixelDotEffect *> pixelEffects;
    
    float zIndex;
    
    bool killMe;
    
    GameObject * gameObjectToAdd;   //enabling game objects to spawn new game objects
    
    
};
