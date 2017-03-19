//
//  volumeEllipse.cpp
//  AbletonMagnifique
//
//  Created by Scott Campbell on 2017-03-19.
//
//

#include "volumeEllipse.hpp"

void VolumeEllipse::setup(int positionX, int positionY) {
    // set location
    x = positionX;
    y = positionY;
}

void VolumeEllipse::update(float _scaledVol) {
    scaledVol = _scaledVol;
}

void VolumeEllipse::draw() {
    
    // draw the average volume:
    ofSetColor(245, 58, 135);
    ofFill();
    ofDrawCircle(x, y, scaledVol * 190.0f);
}

