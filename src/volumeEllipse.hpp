//
//  volumeEllipse.hpp
//  AbletonMagnifique
//
//  Created by Scott Campbell on 2017-03-19.
//
//

#ifndef volumeEllipse_hpp
#define volumeEllipse_hpp

#include <ofMain.h>

class VolumeEllipse {
    
public:
    void draw();
    void update(float _scaledVol);
    void setup(int positionX, int positionY);
    
    int x; // location x
    int y; // location y
    float scaledVol;
};



#endif /* volumeEllipse_hpp */
