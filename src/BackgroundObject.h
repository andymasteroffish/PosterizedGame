#pragma once

#include "ofMain.h"
#include "GameObject.h"
#include "BasicInfo.h"

class BackgroundObject : public GameObject {
	public:
		
    void setupCustom();
    void drawCustom();
    
    ofVec2f pos;
    
};
