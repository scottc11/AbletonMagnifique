//
//  HistographClass.cpp
//  AbletonMagnifique
//
//  Created by Scott Campbell on 2016-10-23.
//
//

#include "HistographClass.hpp"


void Histograph::setup(int _graphLength, int _locX, int _locY) {
    graphLength = _graphLength;
    
    // the location in the window for where the graph should start drawing
    startX = _locX;
    startY = _locY;
}


void Histograph::update(float scaledVol) {
    
    // record the volume into an array
    volHistory.push_back( scaledVol );
    
    // if volHistory is bigger than the size we want to record - drop the oldest value
    if( volHistory.size() >= graphLength ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }
}

void Histograph::draw() {
    
    // draw the volume history as a graph
    
    ofBeginShape();
        for (unsigned int i = 0; i < volHistory.size(); i++){
            if( i == 0 ) ofVertex(startX + i, startY);
        
            ofVertex(startX + i, startY - volHistory[i] * 70);
        
            if( i == volHistory.size() -1 ) ofVertex(startX + i, startY);
        }
    ofEndShape(false);
    
}
