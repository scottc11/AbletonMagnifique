#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    live.setup();
    
    // ABLETON LIVE ADD-ON
    
    // live.printAll();
    int numTracks = live.getNumTracks();
    // ofxAbletonLiveTrack *track = live.getTrack(1);
    
    
    // setting the tempo
    live.setTempo(132);
    tempo = live.getTempo();
    
    
    
    // SOUND/AUDIO SOURCE
    
    soundStream.printDeviceList();
    
    soundStream.setDeviceID(4);  // setting the audio device to an index of deviceList
    
    soundStream.setup(this, 0, 2, 48000, 512, 4);
    
    
    // this code is from the audioIn example
    // and is needed for app to work
    int bufferSize = 512;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    
    
    std::cout << "ABLETON " << endl;
    std::cout << "tempo: " << tempo << endl;
    std::cout << "Number of Tracks: " << numTracks << endl;
    
    std::cout << " " << endl;
    std::cout << "SOUND DEVICE" << endl;
    std::cout << "name: " << soundDevice.name << endl;
    std::cout << "is default input: " << soundDevice.isDefaultInput << endl;
    std::cout << "is default output: " << soundDevice.isDefaultOutput << endl;
    std::cout << "input channels: " << soundDevice << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    live.update();
    scaledVol = ofMap(volume, 0.0, 0.17, 0.0, 1.0, true);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    // draw the average volume:
    ofDrawBitmapString("Current volume of left and right channels combined: " + ofToString(scaledVol * 100.0, 0), 4, 18);
    
    ofSetColor(245, 58, 135);
    ofFill();
    ofDrawCircle(200, 200, scaledVol * 190.0f);
}



//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
    for (int i = 0; i < bufferSize; i++){
        
        left[i]	= input[i*2]*0.5;
        right[i] = input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
    }
    
    volume = curVol;
}

void ofApp::audioOut(ofSoundBuffer & output){
    
    
}



