//
//  AnimationState.hpp
//  paper_doll_animator
//
//  Created by Andrew Wallace on 4/1/16.
//
//

#ifndef AnimationState_hpp
#define AnimationState_hpp

#include "ofMain.h"
#include "AnimationTimeline.hpp"

class AnimationState{
public:
    
    void setup(string _name, float _animationTime, float _transitionTime, bool _doesLoop);
    
    void addTimeline(string timelineName);
    
    AnimationNode getCurNode(int timelineIndex);
    AnimationNode getNextNode(int timelineIndex);
    
    
    string name;
    bool doesLoop;
    float animationTime;
    float transitionTime;
    
    vector<AnimationTimeline> timelines;
    
    
    
};

#endif /* AnimationState_hpp */
