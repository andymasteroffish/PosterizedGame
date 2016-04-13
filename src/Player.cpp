#include "Player.h"


void Player::setupCustom(){
    objectName = "player";
    layer = LAYER_PLAYER;
    
    walkSpeed = 0.34;
    
    drawW = 40;
    drawH = 80;
    addRectangularHitBox(drawW, drawH);
    
    holdingLeft = false;
    holdingRight = false;
    dir = 1;
    
    pos.x = GAME_W * 0.5;
    pos.y = GAME_H * 0.5;
    
    heartbeatEffect = new HeartbeatEffect();
    pixelEffects.push_back(heartbeatEffect);
    
    laserChargeEffect = new LaserChargeEffect();
    laserChargeEffect->isActive = false;
    pixelEffects.push_back(laserChargeEffect);
    
    isChargingShot = false;
    shotChargeTimer = 0;
    
    //figuring out when we are touching other objects
    groundRayStartOffset.set(0, drawH/2);
    groundRayEndOffset.set(0, drawH/2+5);
    
    //falling
    yVel = 0;
    grav = 0.03;
    jumpPower = 2;
    
    //temporary walking cycle
    walkPics.assign(10, ofImage());
    for (int i=0; i<10; i++){
        walkPics[i].loadImage("walk/angry_walk"+ofToString(i)+".png");
    }
    walkFrameTime = 0.1;
    curWalkFrame = 0;
    walkFrameTimer = 0;
    
    
}

void Player::updateCustom(){
    
    if (holdingLeft){
        pos.x -= walkSpeed;
        dir = -1;
    }
    if (holdingRight){
        pos.x += walkSpeed;
        dir = 1;
    }
    
    if (isChargingShot){
        //cout<<"timer "<<shotChargeTimer<<endl;
        shotChargeTimer += deltaTime;
    }
    
    //are we gorunded?
    RaycastInfo thisRay = raycast(pos+groundRayStartOffset, pos+groundRayEndOffset);
    //cout<<"I hit layer "<<thisRay.hitObjectLayerName<<" at "<<thisRay.hitPoint<<endl;
    if (thisRay.hitObject != NULL){
        if (thisRay.hitObject->layer == LAYER_TERRAIN && yVel >= 0){
            isGrounded = true;
            //put us on the ground if we're coming down
            pos.y = thisRay.hitPoint.y - groundRayStartOffset.y;
            
        }else{
            isGrounded = false;
        }
    }else{
        isGrounded = false;
    }
    
    //if not, fall
    if (!isGrounded){
        yVel += grav;
        pos.y += yVel;
    }else{
        yVel = 0;
    }
    
    //walking animaiton
    walkFrameTimer += deltaTime;
    if (walkFrameTimer >= walkFrameTime){
        walkFrameTimer = 0;
        curWalkFrame++;
        if (curWalkFrame >= walkPics.size()){
            curWalkFrame = 0;
        }
    }
    
}

void Player::drawCustom(){
    
    ofSetColor(0, 0, 0);
    
    //ofRect(pos.x-drawW/2, pos.y-drawH/2, drawW, drawH);
    
    //ofSetColor( ofColor::purple );
    //ofLine(pos+groundRayStartOffset, pos+groundRayEndOffset);
    
    ofSetColor(255);
    float walkPicScale = 0.15;//(float)drawH / (float)walkPics[0].height;
    //cout<<walkPicScale<<endl;
    walkPics[curWalkFrame].draw(pos.x-drawW/2, pos.y-drawH/2 - 18, walkPics[curWalkFrame].getWidth()*walkPicScale, walkPics[curWalkFrame].getHeight()*walkPicScale);
    
    //tetsing
    //ofSetColor(255,0,0);
    //ofCircle(heartPos.x, heartPos.y, 3);
    
}

void Player::keyPressed(int key){
    if (key == 356)  holdingLeft = true;
    if (key == 358) holdingRight = true;
    
    if (key == 357 && isGrounded){    //up arrow
        startJump();
    }
    
    if (key == ' ' && !isChargingShot){
        isChargingShot = true;
        laserChargeEffect->isActive = true;
        shotChargeTimer = 0;
    }
    
    //cout<<"key "<<key<<endl;
    
}
void Player::keyReleased(int key){
    if (key == 356)  holdingLeft = false;
    if (key == 358) holdingRight = false;
    
    if (key == ' '){
        isChargingShot = false;
        laserChargeEffect->isActive = false;
        LaserBlast * newBlast = new LaserBlast();
        newBlast->setFromShooter(pos, dir, shotChargeTimer);
        gameObjectToAdd = newBlast;
    }
}

void Player::startJump(){
    yVel = -jumpPower;
}