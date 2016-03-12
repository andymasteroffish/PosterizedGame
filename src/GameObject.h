#pragma once

#include "ofMain.h"
#include "PixelDotEffect.h"
#include "RaycastInfo.h"
#include "HitBox.h"
#include "BasicInfo.h"



class GameObject {
	public:
	
    void setup(vector<GameObject *> * _allGameObjects);
    virtual void setupCustom() {}
    
    void update(float _deltaTime);
    virtual void updateCustom() {}
    
    void draw();
    virtual void drawCustom() {}
    
    virtual void drawDebug();
    
    void addMyPixelEffectsToVector(vector<PixelDotEffect*> * targetVector);
    
    HitBoxRect * addRectangularHitBox(int width, int height);
    HitBoxCircle * addCircleHitBox(float size);
    
    bool checkIfPointIsInHitBoxes(ofVec2f testPoint);
    
    RaycastInfo raycast(ofVec2f startPos, ofVec2f endPos, GameObjectLayer layerToIgnore = LAYER_NONE, GameObjectLayer layerToFocus = LAYER_NONE);
    
    GameObject * findGameObjectWithLayer(GameObjectLayer layer);
    
    void markForDeath();
    virtual void customDeathEffects(){}
    
    void destroy();
    virtual void destroyCustom(){}
    
    
    
    //general info
    float deltaTime;
    bool killMe;
    string objectName;
    GameObjectLayer layer;
    
    vector<GameObject *> * allGameObjects;
    
    //hitbox(s)
    vector<HitBox *> hitBoxes;
    
    //where we are
    ofVec2f pos;
    float zIndex;
    
    //any pixel effects created by this object
    vector<PixelDotEffect *> pixelEffects;
    
    //creating new Game Objects
    GameObject * gameObjectToAdd;   //enabling game objects to spawn new game objects
    
    
};
