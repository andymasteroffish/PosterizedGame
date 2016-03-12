#include "Bullet.h"


Bullet::Bullet(float startX, float startY, int dir, GameObject * _gameObjectToIgnore){
    pos.set(startX, startY);
    vel.set(100, 0);
    vel.x *= dir;
    
    size = 10;
    
    maxLifeTime = 5;
    timer = 0;
}

void Bullet::setupCustom(){
    objectName = "bullet";
}

void Bullet::updateCustom(){
    pos += vel * deltaTime;
    
    timer += deltaTime;
    if (timer >= maxLifeTime){
        killMe = true;
    }
}

void Bullet::drawCustom(){
    ofSetColor(0);
    ofCircle(pos.x, pos.y, size);
}