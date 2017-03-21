//
//  TerrainClass.hpp
//  AbletonMagnifique
//
//  Created by Scott Campbell on 2017-03-19.
//
//

#ifndef TerrainClass_hpp
#define TerrainClass_hpp

#include <ofMain.h>

class Terrain {
public:
    void setup();
    void draw();
    
    ofVboMesh mesh;
    
    int cols;
    int rows;
    int scale = 20;
    
    // terrain width and height (not suppose to be window width/height)
    int w = ofGetWindowWidth();
    int h = ofGetWindowHeight();
    
    float flying = 0;
    
    vector < vector<float> > terrain;
    
    
    
};



#endif /* TerrainClass_hpp */



// ------------------------------------------
// ofBook - Graphics / advanced graphics / 3D
// ------------------------------------------

// The FOV, or field of view, is the angle that the virtual camera,
// that we are looking through, can see.


// ofVboMesh vs. ofMesh --> when ofVboMesh is drawn, instead of uploading all the
// vertices to the graphics card every time draw() is called on it, it uploads
// them once when we draw for the first time and only uploads them again if they change.

// There's a case where using an ofVboMesh might be slower than ofMesh, and that's
// if we want to draw an ofVboMesh, modify it's vertices and then draw it
// again in the same frame.
