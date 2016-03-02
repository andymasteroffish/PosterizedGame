#include "GameObject.h"


void GameObject::setup(){
    setupCustom();
}

void GameObject::update(float _deltaTime){
    deltaTime = _deltaTime;
    updateCustom();
}

void GameObject::draw(){
    drawCustom();
}



void GameObject::addMyPixelEffectsToVector(vector<PixelDotEffect *> * targetVector){
    for (int i=0; i<pixelEffects.size(); i++){
        targetVector->push_back( pixelEffects[i]);
    }
}

void GameObject::destroy(){
    
    //delete all pixel effects
    for (int i=0; i<pixelEffects.size(); i++){
        delete pixelEffects[i];
    }
}