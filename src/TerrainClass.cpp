//
//  TerrainClass.cpp
//  AbletonMagnifique
//
//  Created by Scott Campbell on 2017-03-19.
//
//

#include "TerrainClass.hpp"

void Terrain::setup() {
    
    // Set number of rows and columns
    cols = w / scale;
    rows = h / scale;
    
    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    mesh.enableColors();
    
    
    
    

    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            mesh.addVertex(ofVec3f(x * scale, y * scale, 0.0));
            mesh.addColor(ofColor::dimGrey);
            mesh.addVertex(ofVec3f(x * scale, (y + 1) * scale, 0.0));
            mesh.addColor(ofColor::dimGrey);
            
        }
    }
    
    
}

void Terrain::draw() {
    
    
    mesh.draw();
}
