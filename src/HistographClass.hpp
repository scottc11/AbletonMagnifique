//
//  HistographClass.hpp
//  AbletonMagnifique
//
//  Created by Scott Campbell on 2016-10-23.
//
//

#ifndef HistographClass_hpp
#define HistographClass_hpp

#include "ofMain.h"

class Histograph {
    
public:
    void setup(int _graphLength, int _locX, int _locY);
    void update(float scaledVol);
    void draw();
    void getVolHistory();  // not yet implemented
    void setGraphLength(); // not yet implemented
    
    vector <float> volHistory;
    
    int graphLength;
    int startX;
    int startY;
};


#endif /* HistographClass_hpp */


// REMEMBER THAT YOU NEED TO POPULATE THIS CLASS WITH A SCALED VOLUME - WHICH
// CAN BE PASSED VIA THE UPDATE() METHOD
