//
//  AnimationController.hpp
//  posterized
//
//  Created by Andrew Wallace on 4/13/16.
//
//

#ifndef AnimationController_hpp
#define AnimationController_hpp

#include "ofMain.h"
#include "AnimaitonLimb.h"
#include "AnimationState.hpp"
#include "AnimationTimeline.hpp"

class AnimaitonController{
public:
  
    void setup(string fileName);
    void update(float deltaTime);
    void draw();
    
    void switchAnimations(string animationName);
    
    void loadAnimation(string fileName);
    
    void destroy();
    
    vector<AnimationLimb> limbs;
    vector<AnimaitonState> animations;
    
    float curTime;
    
    
};

#endif /* AnimationController_hpp */
