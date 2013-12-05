//
//  Clockbug.h
//  Clockbugs
//
//  Created by Jeffrey Crouse on 11/23/13.
//
//

#pragma once
#include "ofMain.h"
#include "ofxSpeech.h"


#define CLOCK_TOP -PI/2
#define BUG_TYPE_HOUR_HAND 0
#define BUG_TYPE_MINUTE_HAND 1
#define BUG_TYPE_SECOND_HAND 2

class Clockbug {
public:
    void setup();
    void update();
    void draw();
    
    float maximumDistance; // how far away can the bug go from the center?
    int type;   // Is this an hour bug, a minute bug, or a second bug?
    ofColor color;
    float size;
    ofPoint pos;
    float slow;
    float noise[2];
};
