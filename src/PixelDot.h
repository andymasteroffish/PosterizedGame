#pragma once

#include "ofMain.h"
#include "BasicInfo.h"

class PixelDot {
	public:
    
    void setup(int col, int row, float spacing, int gameX, int gameY);
    void clearEffects();
    void update(unsigned char * bwPix);
    void draw();
    
    int getPixelArrayPos(int x, int y);
    
    ofVec2f screenPos;
    float maxSize;
    
    vector<int> pixelsIDsToAverage;
    float pixelValue;
    
    
    float curValue;
    float curSize;
    float xeno;
    
    //things for effects
    ofColor col;
    float effectScale;
               
            
            
    
		
    
    
};
