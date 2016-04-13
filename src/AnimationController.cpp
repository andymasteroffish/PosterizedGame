//
//  AnimationController.cpp
//  posterized
//
//  Created by Andrew Wallace on 4/13/16.
//
//

#include "AnimationController.hpp"

void AnimationController::setup(string fileName){
    loadAnimation(fileName);
    
    setCurrentAnimation(0);
}

void AnimationController::update(float deltaTime){
    
    curTime += deltaTime;
    if (curTime > animations[curAnimation].animationTime){
        curTime -= animations[curAnimation].animationTime;
    }
    
    
    for (int i=0; i<limbs.size(); i++){
        animations[curAnimation].timelines[i].update(curTime);
        
        AnimationNode curNode = animations[curAnimation].getCurNode(i);
        AnimationNode nextNode = animations[curAnimation].getNextNode(i);
        
        //have the limb set itself based on the previous(current) node and the next node
        limbs[i].update(curTime, curNode, nextNode);
    }
    
}


void AnimationController::draw(bool showDebug){
    
    //draw the limbs
    for (int i=0; i<limbs.size(); i++){
        limbs[i].draw( showDebug );
    }
}

void AnimationController::setCurrentAnimation(string animationName){
    for (int i=0; i<animations.size(); i++){
        if (animations[i].name == animationName){
            setCurrentAnimation(i);
        }
    }
    cout<<"COULD NOT FIND ANIMATION "<<animationName<<endl;
}
void AnimationController::setCurrentAnimation(int animationID){
    if (curAnimation != animationID){
        curAnimation = animationID;
        
        //setup the transition form where the limbs are now to where they should be
        for (int i=0; i<limbs.size(); i++){
            animations[curAnimation].timelines[i].createTransitionNodeFromLimb(limbs[i], animations[curAnimation].transitionTime);
        }
        curTime = -animations[curAnimation].transitionTime;
    }
    
}

void AnimationController::loadAnimation(string fileName){
    ofxXmlSettings xml;
    
    clearAnimations();
    
    if (xml.loadFile(fileName)){
        cout<<"start file load"<<endl;
    }else{
        cout<<"could not load animation file"<<endl;
        return;
    }
    
    xml.pushTag("LIMBS");
    
    //go through and make limbs
    string limbTagName = "LIMB_"+ofToString(0);
    while (xml.tagExists(limbTagName)){
        xml.pushTag(limbTagName);
        
        string limbName = xml.getValue("name", "none");
        string fileName = xml.getValue("file", "none");
        float pivotX = xml.getValue("pivot_x", 0);
        float pivotY = xml.getValue("pivot_y", 0);
        addLimb(limbName, fileName, pivotX, pivotY);
        
        //pop out of this limb
        xml.popTag();
        //setup the next limb
        limbTagName = "LIMB_"+ofToString(limbs.size());
    }
    
    //pop out of LIMBS
    xml.popTag();
    
    xml.pushTag("ANIMATIONS");
    string animationTagName = "ANIMATION_"+ofToString(0);
    while (xml.tagExists(animationTagName)){
        xml.pushTag(animationTagName);
        
        string animationName = xml.getValue("name", "none");
        float animationTime = xml.getValue("length", 3.0f);
        float transitionTime = xml.getValue("transition_time", 0.3f);
        bool doesLoop = xml.getValue("does_loop", 0) == 1;
        
        addAnimation(animationName, animationTime, transitionTime, doesLoop);
        
        //go through the timelines of this animaiton
        //unlike most tags, we know exactly how many there will be because every limb has a timeline
        for (int t=0; t<limbs.size(); t++){
            string timelineTagName = "TIMELINE_"+ofToString(t);
            xml.pushTag(timelineTagName);
            
            animations[animations.size()-1].timelines[t].limbName = limbs[t].name;
            
            //go through the nodes of this timeline
            string nodeTagName = "NODE_"+ofToString(0);
            while (xml.tagExists(nodeTagName)){
                xml.pushTag(nodeTagName);
                
                AnimationNode thisNode;
                thisNode.time = xml.getValue("time", 0.0f);
                thisNode.pos.x = xml.getValue("pos_x", 0.0f);
                thisNode.pos.y = xml.getValue("pos_y", 0.0f);
                thisNode.angle = xml.getValue("angle", 0.0f);
                
                animations[animations.size()-1].timelines[t].nodes.push_back(thisNode);
                
                //pop out of this node
                xml.popTag();
                //get the next node
                nodeTagName = "NODE_"+ofToString(animations[animations.size()-1].timelines[t].nodes.size());
            }
            
            //pop out of this timeline
            xml.popTag();
        }
        
        //pop out of this animation
        xml.popTag();
        
        //set up the next one
        animationTagName = "ANIMATION_"+ofToString(animations.size());
        
    }
    
    //pop out of ANIMATIONS
    xml.popTag();
    
    setCurrentAnimation(0);
    
    cout<<"loaded animation:"<<fileName<<endl;
}

void AnimationController::addLimb(string name, string imgFile, float pivotX, float pivotY){
    
    //create a limb
    AnimationLimb newLimb;
    newLimb.setup(imgFile, name, pivotX, pivotY);
    newLimb.name = name;
    limbs.push_back(newLimb);
    
    //and a timeline for it for every animation
    for (int i=0; i<animations.size(); i++){
        animations[i].addTimeline(name);
    }
}

void AnimationController::addAnimation(string _name, float _animationTime, float _transitionTime, bool _doesLoop){
    AnimationState newAnimation;
    newAnimation.setup( _name,  _animationTime, _transitionTime, _doesLoop);
    
    //create a timeline for every limb
    for (int i=0; i<limbs.size(); i++){
        newAnimation.addTimeline(limbs[i].name);
    }
    
    animations.push_back(newAnimation);
}

void AnimationController::clearAnimations(){
    limbs.clear();
    for (int i=0; i<animations.size(); i++){
        animations[i].timelines.clear();
    }
    animations.clear();
    
}

void AnimationController::destroy(){
    //if you do anything with pointers, make sure to delete them here
}