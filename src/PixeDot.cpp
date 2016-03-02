#include "PixelDot.h"


void PixelDot::setup(int col, int row, float spacing, int gameX, int gameY){
    screenPos.x = col * spacing;
    screenPos.y = row * spacing;
    
    maxSize = spacing * 0.6;
    
    xeno = 0.15;
    
    //go in a box around the center pixel
    int range = 2;
    for (int x = gameX-range; x <= gameX+range; x++){
        for (int y = gameY-range; y <= gameY+range; y++){
            if (x >= 0 && x < GAME_W && y >= 0 && y < GAME_H){
                
                pixelsIDsToAverage.push_back( getPixelArrayPos(x, y));
            }
            
        }
    }
    
    
    
}

void PixelDot::clearEffects(){
    //remove any effects that might be caused by pixel effects on game objects
    col = ofColor::black;
    effectScale = 1;
}

void PixelDot::update(unsigned char * bwPix){

    //get the average value from your bw pixels
    float total = 0;
    for (int i=0; i<pixelsIDsToAverage.size(); i++){
        total += (float)bwPix[pixelsIDsToAverage[i]];
    }
    pixelValue = total / (float)pixelsIDsToAverage.size();
    
    curValue = (1-xeno)*curValue + xeno*pixelValue;
    
    float prc = 1-(curValue/255.0);
    curSize = prc * maxSize * effectScale;
    
}

void PixelDot::draw(){
    ofSetColor(col);
    
    ofCircle(screenPos.x, screenPos.y, curSize);
}


int PixelDot::getPixelArrayPos(int x, int y){
    return x + y * GAME_W;
}