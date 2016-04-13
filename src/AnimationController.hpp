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
#include "ofxXmlSettings.h"
#include "AnimationLimb.hpp"
#include "AnimationState.hpp"
#include "AnimationTimeline.hpp"


class AnimationController{
public:
  
    void setup(string fileName);
    void update(float deltaTime);
    void draw(bool showDebug);
    
    void setCurrentAnimation(string animationName);
    void setCurrentAnimation(int animationID);
    
    void loadAnimation(string fileName);
    void addLimb(string name, string imgFile, float pivotX, float pivotY);
    
    void addAnimation(string _name, float _animationTime, float _transitionTime, bool _doesLoop);
    
    void clearAnimations();
    void destroy();
    
    vector<AnimationLimb> limbs;
    vector<AnimationState> animations;
    
    float curTime;
    int curAnimation;
    
    
};

#endif /* AnimationController_hpp */
