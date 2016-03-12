#pragma once

#include "ofMain.h"
#include "GameObject.h"

class Bullet : public GameObject {
	public:
    
    Bullet(float startX, float startY, int dir, GameObject * _gameObjectToIgnore);
    
    void setupCustom();
    void updateCustom();
    void drawCustom();
    
    ofVec2f vel; //velocity per second
    GameObject * gameObjectToIgnore;
    float size;
    
    float maxLifeTime;
    float timer;
    
    
};

