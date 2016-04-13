#include "GameObject.h"


void GameObject::setup(vector<GameObject *> * _allGameObjects){
    allGameObjects = _allGameObjects;
    zIndex = 0;
    killMe = false;
    gameObjectToAdd = NULL;
    animController = NULL;
    objectName = "none";
    layer = LAYER_DEFAULT;
    setupCustom();
}

void GameObject::update(float _deltaTime){
    deltaTime = _deltaTime;
    
    //do whatever this object does
    updateCustom();
    
    //update the animator if this thing has one
    if (animController != NULL){
        animController->update(deltaTime);
    }
    
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
    
    for (int i=0; i<hitBoxes.size(); i++){
        hitBoxes[i]->drawDebug(pos);
    }
}



void GameObject::addMyPixelEffectsToVector(vector<PixelDotEffect *> * targetVector){
    for (int i=0; i<pixelEffects.size(); i++){
        if (pixelEffects[i]->isActive){
            targetVector->push_back( pixelEffects[i]);
        }
    }
}


HitBoxRect * GameObject::addRectangularHitBox(int width, int height){
    HitBoxRect * newHitbox = new HitBoxRect(0,0, width, height);
    hitBoxes.push_back(newHitbox);
    return newHitbox;
}
HitBoxCircle * GameObject::addCircleHitBox(float size){
    HitBoxCircle * newHitBox = new HitBoxCircle(0,0,size);
    hitBoxes.push_back(newHitBox);
    return newHitBox;
}

bool GameObject::checkIfPointIsInHitBoxes(ofVec2f testPoint){
    //cout<<"checking point "<<testPoint<<" against "<<objectName<<". "<<hitBoxes.size()<<" points"<<endl;
    for (int i=0; i<hitBoxes.size(); i++){
        //cout<<"checking "<<objectName<<" box "<<i<<endl;
        //bool checkVal = hitBoxes[i]->pointIsInside(testPoint, pos);
        //cout<<"checkVal: "<<checkVal<<endl;
        if (hitBoxes[i]->pointIsInside(testPoint, pos) == true){
            //cout<<"inside this hitbox"<<endl;
            return true;
        }
    }
    //cout<<"Not inside one of my hitboxes"<<endl;
    return false;
}

RaycastInfo GameObject::raycast(ofVec2f startPos, ofVec2f endPos, GameObjectLayer layerToIgnore, GameObjectLayer layerToFocus){
    //cout<<"---------------------"<<endl<<"NEW RAY"<<endl;
    ofVec2f totalLine = endPos - startPos;
    ofVec2f step = totalLine.normalized();
    
    int numSteps = totalLine.length();
    
    ofVec2f curPos = startPos;
    for (int i=0; i<numSteps; i++){
        //test curPos against all other gameobjects
        for (int g=0; g<allGameObjects->size(); g++){
            //cout<<"chekcing object "<<g<<" after "<<i<<" steps"<<endl;
            
            //Don't let it check against itself
            if(allGameObjects->at(g) != this && allGameObjects->at(g)->layer != layerToIgnore && (layerToFocus == LAYER_NONE || allGameObjects->at(g)->layer == layerToFocus)){
                if (allGameObjects->at(g)->checkIfPointIsInHitBoxes(curPos) == true){
                    RaycastInfo thisInfo;
                    thisInfo.hitObject = allGameObjects->at(g);
                    thisInfo.hitPoint = curPos;
                    //cout<<"connected with "<<g<<" after "<<i<<" steps"<<endl;
                    return thisInfo;
                }
            }
        }
        
        //move it up
        curPos += step;
    }
    
    RaycastInfo empty;
    empty.clear();
    return empty;
}

void GameObject::markForDeath(){
    killMe = true;
    customDeathEffects();
}

GameObject * GameObject::findGameObjectWithLayer(GameObjectLayer layer){
    for (int i=0; i<allGameObjects->size(); i++){
        if (allGameObjects->at(i)->layer == layer){
            return allGameObjects->at(i);
        }
    }
    return NULL;
}



void GameObject::destroy(){
    
    //delete all pixel effects
    for (int i=0; i<pixelEffects.size(); i++){
        delete pixelEffects[i];
    }
    
    //delete all hotboxes
    for (int i=0; i<hitBoxes.size(); i++){
        delete hitBoxes[i];
    }
    
    if (animController != NULL){
        animController->destroy();
        delete animController;
    }
}


