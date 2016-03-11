#include "TerrainFloor.h"


TerrainFloor::TerrainFloor(float x, float y, float _w, float _h){
    pos.set(x, y);
    w = _w;
    h = _h;
}

void TerrainFloor::setupCustom(){
    
    //creating a new hitbox
    HitBoxRect * thisHitBox = addSquareHitBox(w, h);
    //hitboxes are centered by default, but I want this one to start right at the corner
    thisHitBox->x = 0;
    thisHitBox->y = 0;
    
    zIndex = 10;
    
    objectName = "floor";
    layer = LAYER_TERRAIN;
    
}


void TerrainFloor::drawCustom(){
    
    ofSetColor(30);
    
    ofRect(pos.x, pos.y, w, h);
}
