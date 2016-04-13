//
//  AnimationState.cpp
//  paper_doll_animator
//
//  Created by Andrew Wallace on 4/1/16.
//
//

#include "AnimationState.hpp"


void AnimationState::setup(string _name, float _animationTime, float _transitionTime, bool _doesLoop){
    name = _name;
    animationTime = _animationTime;
    transitionTime = _transitionTime;
    doesLoop = _doesLoop;
    
    timelines.clear();
}

void AnimationState::addTimeline(string timelineName){
    AnimationTimeline newTimeline;
    newTimeline.setup(animationTime, timelineName, doesLoop);
    
    timelines.push_back(newTimeline);
}


AnimationNode AnimationState::getCurNode(int timelineIndex){
    int curNode = timelines[timelineIndex].curNode;
    
    //during transitions, the sleected node will be -1, menaing we should use the transition node
    if (curNode == -1){
        return timelines[timelineIndex].transitionNode;
    }
    
    //otherwise just return the given node
    return timelines[timelineIndex].nodes[curNode];
}

AnimationNode AnimationState::getNextNode(int timelineIndex){
    int nextNode = timelines[timelineIndex].nextNode;
    return timelines[timelineIndex].nodes[nextNode];
}