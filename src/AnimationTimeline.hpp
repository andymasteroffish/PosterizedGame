//
//  AnimationTimeline.hpp
//  posterized
//
//  Created by Andrew Wallace on 4/13/16.
//
//

#ifndef AnimationTimeline_hpp
#define AnimationTimeline_hpp

#include "ofMain.h"
#include "AnimationNode.hpp"
#include "AnimationLimb.hpp"

class AnimationTimeline{
public:
    
    void setup(float _maxTime, string _limbName, bool _animationLoops);
    void update(float _curTime);
    
    void createTransitionNodeFromLimb(AnimationLimb limb, float transitionTime);
    
    //info
    string limbName;
    float maxTime;
    float curTime;
    bool animationLoops;
    vector<AnimationNode> nodes;
    AnimationNode transitionNode;
    
    int curNode;
    int nextNode;
    
    
    
};

#endif /* AnimationTimeline_hpp */
