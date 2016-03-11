//
//  BasicInfo.h
//  emptyExample
//
//  Created by Andrew Wallace on 2/25/16.
//
//

#ifndef emptyExample_BasicInfo_h
#define emptyExample_BasicInfo_h

#define GAME_W 320
#define GAME_H 240

#define DOTS_W 64
#define DOTS_H 48

enum GameObjectLayer { LAYER_DEFAULT, LAYER_TERRAIN };

class GridPos{
public:
    int x, y;
    
    void set(int _x, int _y){
        x = _x;
        y = _y;
    }
};



#endif
