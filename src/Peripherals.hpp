//
//  Peripherals.hpp
//  AbletonMagnifique
//
//  Created by Scott Campbell on 2017-03-19.
//
//

#ifndef Peripherals_hpp
#define Peripherals_hpp

#include <ofMain.h>


class Peripherals {

public:
    void update(float _scaledVol, float _tempo);
    void draw();

    float scaledVol;
    float tempo;

};




#endif /* Peripherals_hpp */
