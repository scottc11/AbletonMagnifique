//
//  Peripherals.cpp
//  AbletonMagnifique
//
//  Created by Scott Campbell on 2017-03-19.
//
//

#include "Peripherals.hpp"

void Peripherals::update(float _scaledVol, float _tempo) {
    scaledVol = _scaledVol;
    tempo = _tempo;
}

void Peripherals::draw() {
    ofSetColor(255);
    ofDrawBitmapString("FrameRate: " + ofToString(ofGetFrameRate()), 4, 40);
    ofDrawBitmapString("Volume:    " + ofToString(scaledVol * 100.0, 0), 4, 20);
    ofDrawBitmapString("Tempo:     " + ofToString(tempo), 4, 60);
}
