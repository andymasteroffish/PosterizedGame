#include "PixelDot.h"


void PixelDot::setup(int col, int row, float _spacing, int gameX, int gameY){
    spacing = _spacing;
    screenPos.x = col * spacing;
    screenPos.y = row * spacing;
    startScreenPos = screenPos;
    
    cout<<col<<" "<<row<<": "<<startScreenPos<<endl;
    
    maxSize = spacing * 0.6;
    
    xeno = 0.3;
    
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
    
    targetScreenPos = startScreenPos;
    moveXeno = 1;
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
    
    //adjust position if anything it affecting it
    screenPos = (1-moveXeno)*screenPos + moveXeno*targetScreenPos;
    
}

void PixelDot::draw(){
    ofSetColor(col);
    
    ofCircle(screenPos.x, screenPos.y, curSize);
}


int PixelDot::getPixelArrayPos(int x, int y){
    return x + y * GAME_W;
}