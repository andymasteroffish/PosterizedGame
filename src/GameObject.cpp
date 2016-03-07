#include "GameObject.h"


void GameObject::setup(){
    zIndex = 0;
    killMe = false;
    gameObjectToAdd = NULL;
    hitBox.set(-5, -5, 10, 10);
    setupCustom();
}

void GameObject::update(float _deltaTime){
    deltaTime = _deltaTime;
    
    //do whatever this objetc does
    updateCustom();
    
    //keep any pixel effects with the object
    for (int i=0; i<pixelEffects.size(); i++){
        pixelEffects[i]->setPosFromParentObject(pos);
    }
    
}

void GameObject::draw(){
    drawCustom();
}

void GameObject::drawDebug(){
    ofSetColor( ofColor::purple);
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRect(hitBox);
    ofPopMatrix();
}



void GameObject::addMyPixelEffectsToVector(vector<PixelDotEffect *> * targetVector){
    for (int i=0; i<pixelEffects.size(); i++){
        if (pixelEffects[i]->isActive){
            targetVector->push_back( pixelEffects[i]);
        }
    }
}

void GameObject::destroy(){
    
    //delete all pixel effects
    for (int i=0; i<pixelEffects.size(); i++){
        delete pixelEffects[i];
    }
}

void GameObject::setHitBox(int width, int height){
    hitBox.width = width;
    hitBox.height = height;
    hitBox.x = -width/2;
    hitBox.y = -height/2;
}


bool GameObject::checkIfPointIsInHitBox(ofVec2f testPoint){
    if (hitBox.inside(testPoint.x, testPoint.y)){
        return true;
    }
    return false;
}

RaycastInfo GameObject::raycast(ofVec2f startPos, ofVec2f endPos){
    ofVec2f totalLine = endPos - startPos;
    ofVec2f step = totalLine.normalized();
    
    int numSteps = step.x / totalLine.x;
    
    ofVec2f curPos;
    for (int i=0; i<numSteps; i++){
        //test curPos against all other gameobjects
        for (int g=0; g<allGameObjects->size(); g++){
            
            //DOES allGameObjects->at(g) != this EVEN WORK?
            if (allGameObjects->at(g) != this && allGameObjects->at(g)->checkIfPointIsInHitBox(curPos)){
                RaycastInfo thisInfo;
                thisInfo.hitObjectID = g;
                thisInfo.hitPoint = curPos;
                return thisInfo;
            }
        }
        
        //move it up
        curPos += step;
    }
    
    RaycastInfo empty;
    empty.hitObjectID = -1;
    return empty;
}






