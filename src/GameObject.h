#pragma once

#include "ofMain.h"
#include "PixelDotEffect.h"
#include "RaycastInfo.h"



class GameObject {
	public:
	
    void setup();
    virtual void setupCustom() {}
    
    void update(float _deltaTime);
    virtual void updateCustom() {}
    
    void draw();
    virtual void drawCustom() {}
    
    virtual void drawDebug();
    
    void destroy();
    virtual void destroyCustom(){}
    
    void addMyPixelEffectsToVector(vector<PixelDotEffect*> * targetVector);
    
    void setHitBox(int width, int height);
    
    bool checkIfPointIsInHitBox(ofVec2f testPoint);
    
    RaycastInfo raycast(ofVec2f startPos, ofVec2f endPos);
    
    
    //general info
    float deltaTime;
    bool killMe;
    
    vector<GameObject *> * allGameObjects;
    
    //hitbox
    ofRectangle hitBox;
    
    //where we are
    ofVec2f pos;
    float zIndex;
    
    //any pixel effects created by this object
    vector<PixelDotEffect *> pixelEffects;
    
    //creating new Game Objects
    GameObject * gameObjectToAdd;   //enabling game objects to spawn new game objects
    
    
};
