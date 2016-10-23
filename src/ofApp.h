#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxAbletonLive.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void audioIn(float * input, int bufferSize, int nChannels);  // function for audio in
    void audioOut(ofSoundBuffer & output);  // function for audio in
    
    

    
    //STANDARD Variables
    
    float tempo;
    
    float HEIGHT;
    float WIDTH;
    
    // Ableton Add-on Variables
    ofxAbletonLive live;
    ofxAbletonLiveTrack *track; // This is a work in progress
    
    
    // Sound / FFT
    ofSoundDevice soundDevice;  // this shit doesn't work
    ofSoundStream soundStream;
    
    vector <float> left; // the left channel
    vector <float> right; // the right channel
    
    int bufferSize;
    int bufferCounter;
    int drawCounter;
    float volume;
    float scaledVol;
    vector <float> volHistory;
};


// In order to read the audio output of your MOTU interface, or any audio interface
// for that matter, you need to use the Application called "SoundFlower" coupled with
// its sister application "SoundFlower Bed".
//
// soundflower - https://github.com/mattingalls/Soundflower/releases/tag/2.0b2
// soundflower bed - https://github.com/mLupine/SoundflowerBed
//
// To do this, launch soundflowerbed from applications, navigate to the soundflower icon
// in the OSX menu by wifi etc.) and set the soundflower ch2. output to your desired audio
// interface.  In this case, MOTU 4pre.  Then you must go to your
// system preferences -> Sound -> and set your audio output to Soundflower (ch2).
// Sometimes it can be finicky, so 'un-setting' and then 're-setting' the Motu 4pre
// as a sound source will fix the issue.
