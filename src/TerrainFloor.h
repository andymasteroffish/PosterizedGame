#pragma once

#include "ofMain.h"
#include "BasicInfo.h"
#include "GameObject.h"

class TerrainFloor : public GameObject {
	public:
    
    TerrainFloor(float x, float y, float _w, float _h);
    void setupCustom();
    void drawCustom();
    
    float w,h;
    
    
};

