#pragma once

#include "ofMain.h"
#include "BasicInfo.h"

class HitBox {
	public:
    
    virtual void drawDebug(ofVec2f parentPos){}
    
    virtual bool pointIsInside(float pointX, float pointY, ofVec2f parentPos){return false;}
    
    bool pointIsInside(ofVec2f point, ofVec2f parentPos){
        return pointIsInside(point.x, point.y, parentPos);
    }
    
    
};


class HitBoxRect : public HitBox{
public:
    
    float x,y, w,h;
    
    HitBoxRect(float centerX, float centerY, float _w, float _h){
        w = _w;
        h = _h;
        x = centerX - w/2;
        y = centerY - h/2;
    }
    
    bool pointIsInside(float pointX, float pointY, ofVec2f parentPos){
        //cout<<"checking "<<pointX<<" "<<pointY<<" against "<<(x+parentPos.x)<<" "<<(y+parentPos.y)<<"   "<<w<<" "<<h<<endl;
        //cout<<"checks: "<<(pointX >= x+parentPos.x)<<"  "<<(pointX <= x+parentPos.x+w)<<"  "<<(pointY >= y+parentPos.y)<<"  "<<(pointY <= y+parentPos.y+h)<<endl;
        if (pointX >= x+parentPos.x && pointX <= x+parentPos.x+w && pointY >= y+parentPos.y && pointY <= y+parentPos.y+h){
            //cout<<"it true"<<endl;
            return true;
        }
        //cout<<"it false"<<endl;
        return false;
    }
    
    void drawDebug(ofVec2f parentPos){
        ofSetColor(255,0,0, 150);
        ofRect(x+parentPos.x, y+parentPos.y, w,h);
    }
};


class HitBoxCircle : public HitBox{
public:
    
    float x,y, size;
    
    HitBoxCircle(float centerX, float centerY, float _size){
        size = _size;
        x = centerX;
        y = centerY;
    }
    
    bool pointIsInside(float pointX, float pointY, ofVec2f parentPos){
        if (ofDist(pointX, pointY, x+parentPos.x, y+parentPos.y) <= size){
            return true;
        }
        return false;
    }
    
    void drawDebug(ofVec2f parentPos){
        ofSetColor(255,0,0, 150);
        ofCircle(x+parentPos.x, y+parentPos.y, size);
    }
};