//
//  AnimationLimb.hpp
//  paper_doll_animator
//
//  Created by Andrew Wallace on 3/30/16.
//
//

#ifndef AnimationLimb_hpp
#define AnimationLimb_hpp

#include "ofMain.h"
#include "AnimationNode.hpp"

class AnimationLimb{
public:
    
    void setup();
    void setup(string imgFile, string _name, float pivotX, float pivotY);
    
    
    void update(float time, AnimationNode prevNode, AnimationNode nextNode);
    void draw(bool useDebugColor);
    
    void randomizeDebugColor();
    
    string name;
    
    ofVec2f pos;
    float angle;
    
    ofVec2f pivotPoint;
    
    ofImage img;
    
    ofColor debugDrawCol;
    
};

#endif /* AnimationLimb_hpp */
