#include "Turret.h"

Turret::Turret(float startX, float startY){
    pos.set(startX, startY);
}

void Turret::setupCustom(){
    objectName = "turret";
    layer = LAYER_FOE;
    
    timeBetweenShots = 5;
    shotTimer = 0;
    
    
    drawW = 20;
    drawH = 60;
    
    addRectangularHitBox(drawW, drawH);
    
    player = findGameObjectWithLayer(LAYER_PLAYER);
    rangeToShootPlayer = GAME_W;
}

void Turret::updateCustom(){
    
    if (ofDistSquared(player->pos.x, player->pos.y, pos.x, pos.y) < rangeToShootPlayer*rangeToShootPlayer){
        shotTimer += deltaTime;
        
        if (shotTimer >= timeBetweenShots){
            shoot();
        }
    }
    
}

void Turret::drawCustom(){
    ofSetColor(0);
    ofRect(pos.x-drawW/2, pos.y-drawH/2, drawW, drawH);
}

void Turret::shoot(){
    int dir = 1;
    if (player->pos.x < pos.x){
        dir = -1;
    }
    
    Bullet * bullet = new Bullet(pos.x, pos.y, dir, this );
    gameObjectToAdd = bullet;
    
    shotTimer = 0;
}