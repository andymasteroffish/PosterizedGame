#pragma once

#include "ofMain.h"
#include "BasicInfo.h"

class PixelDot {
	public:
    
    void setup(int col, int row, float _spacing, int gameX, int gameY);
    void clearEffects();
    void update(unsigned char * bwPix);
    void draw();
    
    int getPixelArrayPos(int x, int y);
    
    float spacing;
    ofVec2f screenPos, startScreenPos;
    float maxSize;
    
    vector<int> pixelsIDsToAverage;
    float pixelValue;
    
    
    float curValue;
    float curSize;
    float xeno;
    
    //things for effects
    ofColor col;
    float effectScale;
    
    //moving around
    float moveXeno;
    ofVec2f targetScreenPos;
            
            
    
		
    
    
};
