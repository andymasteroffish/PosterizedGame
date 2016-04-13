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

class AnimationTimeline{
public:
    
    void setup(float _maxTime, string _limbName, bool _animationLoops);
    void update(float _curTime);
    
    //info
    string limbName;
    float maxTime;
    float curTime;
    bool animationLoops;
    vector<AnimationNode> nodes;
    
    int selectedNode;   //this could be called curNode. This name is a hold over from the animation tool
    int nextNode;
    
    
    
};

#endif /* AnimationTimeline_hpp */
