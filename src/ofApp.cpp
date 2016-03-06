#include "ofApp.h"


bool dotSort(  PixelDot * a, PixelDot * b ) {
    return a->curSize < b->curSize;
}

bool sortGameObjectsOnZIndex(  GameObject * a, GameObject * b ) {
    return a->zIndex > b->zIndex;
}

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    
    fbo.allocate(GAME_W, GAME_H, GL_RGB);
    
    rawPix  = new unsigned char [GAME_W * GAME_H * 3];
    bwPix = new unsigned char [GAME_W * GAME_H];
    avgPix = new unsigned char [DOTS_W * DOTS_H];
    
    float dotsSpacing = (float)ofGetWidth()/(float)DOTS_W;
    float dotSpaceToGameSpace = (float)GAME_W / (float)DOTS_W;
    for (int x=0; x<DOTS_W; x++){
        for (int y=0; y<DOTS_H; y++){
            dots[x][y].setup(x, y, dotsSpacing, x*dotSpaceToGameSpace, y*dotSpaceToGameSpace);
            sortedDots.push_back(&dots[x][y]);
        }
    }
    
    
    debugShowFBO = true;
    
    distFromEdgeToScroll = GAME_W * 0.4;
    scrollXeno = 0.5;
    
    reset();

    prevFrameTime = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::reset(){
    scrollPos.set(0,0);
    scrollTarget = scrollPos;
    
    player.setup();
    gameObjects.push_back(&player);
    
    //some bg objects to test scrolling
    for (int i=0; i<5; i++){
        BackgroundObject * bgObject = new BackgroundObject();
        bgObject->setup();
        gameObjects.push_back(bgObject);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    deltaTime = ofGetElapsedTimef()-prevFrameTime;
    prevFrameTime = ofGetElapsedTimef();
    
    //update the game objects
    for (int i=0; i<gameObjects.size(); i++){
        gameObjects[i]->update(deltaTime);
        
        //did this thing create a new game object?
        if (gameObjects[i]->gameObjectToAdd != NULL){
            setupNewGameObject(gameObjects[i]->gameObjectToAdd);
            gameObjects[i]->gameObjectToAdd = NULL; //turn off the flag onc eit has been added to the vector
        }
        
        //is it time for this thing to die?
        if (gameObjects[i]->killMe){
            killGameObject(i);
        }
    }
    
    //check if we need to scroll
    if (player.pos.x+scrollTarget.x > GAME_W-distFromEdgeToScroll){
        scrollTarget.x -= (player.pos.x+scrollTarget.x) - (GAME_W-distFromEdgeToScroll);
    }
    if (player.pos.x+scrollTarget.x < distFromEdgeToScroll){
        scrollTarget.x -= (player.pos.x+scrollTarget.x) - (distFromEdgeToScroll);
    }
    scrollPos = (1-scrollXeno)*scrollPos + scrollXeno * scrollTarget;
    
    
    
    //draw the game
    drawGameFBO();
    
    //get the pixel info from the FBO
    ofPixels pix;
    fbo.readToPixels(pix);
    
    rawPix = pix.getPixels();
    
    for (int i=0; i< GAME_W*GAME_H; i++){
        int rgbPos = i*3;
        int rVal = rawPix[rgbPos];
        int gVal = rawPix[rgbPos+1];
        int bVal = rawPix[rgbPos+2];
        
        //mix down to bw
        int maxVal = MIN(rVal, MIN(gVal, bVal));
        bwPix[i] = (char) maxVal;
    }
    
    
    //clear the effects form all pixel dots
    for (int x=0; x<DOTS_W; x++){
        for (int y=0; y<DOTS_H; y++){
            dots[x][y].clearEffects();
        }
    }
    
    //pixel dot effects
    vector<PixelDotEffect *> effects;
    
    //go through each game object and get all effects
    for (int i=0; i<gameObjects.size(); i++){
        gameObjects[i]->addMyPixelEffectsToVector(&effects);
    }
    
    //sort them if they need to be sorted
    
    //go through the vector and apply all effects
    for (int i=0; i<effects.size(); i++){
        effects[i]->applyEffectToDot(dots, scrollPos, deltaTime);
    }
    
    //let the pixel dots process themselves
    for (int x=0; x<DOTS_W; x++){
        for (int y=0; y<DOTS_H; y++){
            dots[x][y].update(bwPix);
        }
    }
    
    
    
    
        
    
}

//--------------------------------------------------------------
void ofApp::drawGameFBO(){
    //draw the game into the FBP
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    fbo.begin();
    ofClear(255);
    
    ofPushMatrix();
    ofTranslate(scrollPos.x, scrollPos.y);
    
    
    //some background noise
    for (int i=0; i<20; i++){
        ofSetColor( ofRandom(150,255) );
        ofPushMatrix();
        ofTranslate(ofRandom(GAME_W), ofRandom(GAME_H));
        ofRotate(ofRandom(360));
        ofRect( 0,0, 20, 20);
        ofPopMatrix();
    }
    
    //draw the gameobjects
    sort(gameObjects.begin(), gameObjects.end(), sortGameObjectsOnZIndex);
    for (int i=0; i<gameObjects.size(); i++){
        gameObjects[i]->draw();
    }
    
    ofPopMatrix();
    
    fbo.end();
    ofDisableSmoothing();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //sort dots by size
    sort(sortedDots.begin(), sortedDots.end(), dotSort );
    
    //draw the pixel dots
    //ofSetColor(0);
    for (int i=0; i<sortedDots.size(); i++){
        sortedDots[i]->draw();
    }
    
    //draw debug info
    if (debugShowFBO){
        ofSetColor(255);
        fbo.draw(0,0, GAME_W, GAME_H);
        
        ofSetColor(255,0,0);
        ofDrawBitmapString("FPS: "+ofToString(ofGetFrameRate()), ofGetWidth()-100, 40);
        ofDrawBitmapString("objects: "+ofToString(gameObjects.size()), ofGetWidth()-100, 55);
    }
    
}

//--------------------------------------------------------------
//initiating and killing game objects
void ofApp::setupNewGameObject(GameObject *newObject){
    newObject->setup();
    gameObjects.push_back(newObject);
}

void ofApp::killGameObject(int index){
    gameObjects[index]->destroy();
    gameObjects.erase(gameObjects.begin()+index);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    player.keyPressed(key);
    if (key == 'h')     debugShowFBO = !debugShowFBO;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    player.keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}