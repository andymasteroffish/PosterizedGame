//
//  AnimationLimb.cpp
//  paper_doll_animator
//
//  Created by Andrew Wallace on 3/30/16.
//
//

#include "AnimationLimb.hpp"

void AnimationLimb::setup(){
    setup("none", "none", 0, 0);
    
}

void AnimationLimb::setup(string imgFile, string _name, float pivotX, float pivotY){
    
    img.load(imgFile);
    
    name = _name;
    
    pos.set(0,0);
    angle = 0;
    
    pivotPoint.set(pivotX, pivotY);
    
    randomizeDebugColor();
    
}


void AnimationLimb::update(float time, AnimationNode prevNode, AnimationNode nextNode){
    
    float prc = (time - prevNode.time) / (nextNode.time-prevNode.time);
    
    //lerp between the points
    pos = (1-prc) * prevNode.pos + prc * nextNode.pos;
    angle = (1-prc) * prevNode.angle + prc * nextNode.angle;
    
}

void AnimationLimb::draw(bool useDebugColor){
    ofSetColor(0);
    
    if (useDebugColor){
        ofSetColor(debugDrawCol);
    }
    
    ofPushMatrix();
    
    ofTranslate(pos.x, pos.y);
    ofRotate(angle);
    
    ofTranslate(pivotPoint.x, pivotPoint.y);
    
    img.draw(-img.getWidth()/2, -img.getHeight()/2);
    
    
    ofPopMatrix();
    
    //testing pivot point
    if (useDebugColor){
        ofPushMatrix();
        ofNoFill();
        ofTranslate(pos.x, pos.y);
        
        ofSetColor(0,0,255);
        ofDrawCircle(0,0, 3);
        
        ofPopMatrix();
    }
    
}

void AnimationLimb::randomizeDebugColor(){
    debugDrawCol.setHsb(ofRandom(255), 255, 255);
    debugDrawCol.a = 180;
}