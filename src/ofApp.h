#pragma once

#include "ofMain.h"
#include "BasicInfo.h"

#include "PixelDot.h"

#include "PixelDotEffect.h"

#include "Player.h"
#include "BackgroundObject.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void reset();
    void update();
    void drawGameFBO();
    void draw();
    
    void setupNewGameObject(GameObject * newObject);
    void killGameObject(int index);
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //general info
    float deltaTime, prevFrameTime;
    
    //delaing with the pixels
    unsigned char * rawPix;
    unsigned char * bwPix;
    unsigned char * avgPix;
    
    PixelDot dots[DOTS_W][DOTS_H];
    vector<PixelDot *> sortedDots;
    
    //drawing the game into an FBO
    ofFbo fbo;
    bool debugShowFBO;
    bool showDebugInfo;
    
    //scrolling
    ofVec2f scrollPos, scrollTarget;
    float scrollXeno;
    float distFromEdgeToScroll;
    
    //game elements
    vector<GameObject *> gameObjects;
    Player player;
    
};
