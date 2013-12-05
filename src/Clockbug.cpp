//
//  Clockbug.cpp
//  Clockbugs
//
//  Created by Jeffrey Crouse on 11/23/13.
//
//

#include "Clockbug.h"

// ---------------------------------
void Clockbug::setup()
{
    ofBackground(0);
    pos.set(0, 0);
    noise[0] = ofRandomf();
    noise[1] = ofRandomf();
    
    // Pick a random type
    type = ofRandom(0, 3);
    
    // Set some variables based on the type.
    if(type==BUG_TYPE_HOUR_HAND)
    {
        color = ofColor::white;
        maximumDistance = 350;
        size = 3;
        slow = 10.0;
    }
    if(type==BUG_TYPE_MINUTE_HAND)
    {
        color = ofColor::white;
        maximumDistance = 450;
        size = 2;
        slow = 6.0;
    }
    if(type==BUG_TYPE_SECOND_HAND)
    {
        color = ofColor::white;
        maximumDistance = 300;
        size = 1;
        slow = 3.0;
    }
}

// ---------------------------------
void Clockbug::update()
{
    // Our goal here is to calculate 2 things: target angle and target distance
    
    
    // Which angle should the bug be at?
    // Hint: this depends on which "type" it is
    float targetAngle;
    if(type==BUG_TYPE_HOUR_HAND) {
        float hours = ofGetHours() + (ofGetMinutes()/60.0) + (ofGetSeconds()/3600.0);
        targetAngle = ofMap(hours, 0, 12, CLOCK_TOP, CLOCK_TOP+M_TWO_PI);
    }
    if(type==BUG_TYPE_MINUTE_HAND) {
        float minutes = ofGetMinutes() + (ofGetSeconds()/60.0);
        targetAngle = ofMap(minutes, 0, 60, CLOCK_TOP, CLOCK_TOP+M_TWO_PI);
    }
    if(type==BUG_TYPE_SECOND_HAND) {
        float seconds = ofGetSeconds();
        targetAngle = ofMap(seconds, 0, 60, CLOCK_TOP, CLOCK_TOP+M_TWO_PI);
    }
    
    
    // Calculate some "noise" -- smoothly changing random values
    // This will give us a value between 0 and 1.
    float angleNoise = ofNoise(noise[0], ofGetElapsedTimef()/slow);
    // change the noise value from [0 -> 1] to [-5 -> 5]
    angleNoise = ofMap(angleNoise, 0, 1, ofDegToRad(-5), ofDegToRad(5));
    
    // Add that noise to the target angle.  This will make the bug move
    // a little bit (+/- 5 degrees) around it's target angle
    targetAngle += angleNoise;
    
    // Now that we have determined the angle the bug will be at,
    // we will calculate how far away from the center it should be.
    // once again, we get smoothly changing noise [0 -> 1]
    // and then calculate the dist on the scale of [0 -> maximumDistance]
    float dist = ofNoise(noise[1], ofGetElapsedTimef()/slow);
    float targetDist = ofMap(dist, 0, 1, 0, maximumDistance);
    
    
    // Calculate where the bug should be moving towards
    // Here we are converting from radial to cartesian.
    ofPoint target;
    target.x = cos(targetAngle) * targetDist;
    target.y = sin(targetAngle) * targetDist;
    
    
    // Move towards target point
    ofPoint diff = target - pos;
    pos += diff / 10.0;
}

// ---------------------------------
void Clockbug::draw()
{
    ofPushStyle();
    ofSetColor(color);
    ofCircle(pos, size);
    ofPopStyle();
}
