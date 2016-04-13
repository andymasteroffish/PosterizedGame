//
//  AnimationTimeline.cpp
//  posterized
//
//  Created by Andrew Wallace on 4/13/16.
//
//

#include "AnimationTimeline.hpp"

void AnimationTimeline::setup(float _maxTime, string _limbName, bool _animationLoops){
    
    maxTime = _maxTime;
    curTime = 0;
    
    limbName =  _limbName;
    
    animationLoops = _animationLoops;
    
    nodes.clear();
    
    selectedNode = 0;
    
}


void AnimationTimeline::update(float _curTime){
    curTime = _curTime;
    
    //selected node should be the one before the current point on the timeline
    selectedNode = 0;
    for (int i=0; i<nodes.size(); i++){
        if (nodes[i].time <= curTime){
            selectedNode = i;
        }else{
            break;
        }
    }
    
    //during transitions, the selected node is the transition node, denoted by -1
    if (curTime < 0){
        selectedNode = -1;
    }
    
    //the next node is the one after the selected node, or looping back to the first
    nextNode = selectedNode+1;
    if (nextNode >= nodes.size()){
        nextNode = 0;
    }
    
    
}

void AnimationTimeline::createTransitionNodeFromLimb(AnimationLimb limb, float transitionTime){
    transitionNode.pos = limb.pos;
    transitionNode.angle = limb.angle;
    transitionNode.time = -transitionTime;
}
