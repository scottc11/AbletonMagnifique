#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0, 0, 0);
    HEIGHT = ofGetWindowHeight();
    WIDTH = ofGetWindowWidth();
    
    
    // ABLETON LIVE ADD-ON
    live.setup();
    
    // live.printAll();
    int numTracks = live.getNumTracks();
    // ofxAbletonLiveTrack *track = live.getTrack(1);
    
    // HISTOGRAPH of volume
    histograph.setup(WIDTH/3, (WIDTH/3 + (WIDTH/3)), 70);
    
    // setting the tempo
    live.setTempo(132);
    tempo = live.getTempo();
    
    
    
    // SOUND/AUDIO SOURCE
    
    soundStream.printDeviceList();
    
    soundStream.setDeviceID(4);  // setting the audio device to an index of deviceList
    bufferSize = 512; // init a buffer size
    soundStream.setup(this, 0, 2, 48000, bufferSize, 4);
    
    
    // this code is from the audioIn example and is needed for app to work
    
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    bufferCounter = 0;
    drawCounter	= 0;
    volume = 0.0;
    scaledVol = 0.0;
    
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
    tempo = live.getTempo();
    scaledVol = ofMap(volume, 0.0, 0.17, 0.0, 1.0, true);
    
    histograph.update(scaledVol);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    // draw the average volume:
    
    
    ofSetColor(245, 58, 135);
    ofFill();
    ofDrawCircle(WIDTH/2, HEIGHT/2, scaledVol * 190.0f);
    
    
    histograph.draw();
    
    
    // Graphical Interface
    ofSetColor(255);
    ofDrawBitmapString("FrameRate: " + ofToString(ofGetFrameRate()), 4, 40);
    ofDrawBitmapString("Volume:    " + ofToString(scaledVol * 100.0, 0), 4, 20);
    ofDrawBitmapString("Tempo:     " + ofToString(tempo), 4, 60);
    
}



//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    // lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        
        left[i]	= input[i*2]*0.5;
        right[i] = input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted += 2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    volume *= 0.93;
    volume += 0.07 * curVol;
    
    bufferCounter++;
}

void ofApp::audioOut(ofSoundBuffer & output){
    
    
}



