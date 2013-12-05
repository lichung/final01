#pragma once

#include "ofMain.h"
#include "ofxSpeech.h"
#include "Clockbug.h"


class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    vector<Clockbug> bugs;
    ofTrueTypeFont font;
    
    //-- Define function to handle the speech recognition event
    void speechRecognized(string & wordRecognized);
    
    
    ofxSpeechRecognizer         recognizer;
    bool                        drawCircle;
    bool                        light;
    int                         circle_x;
    int                         circle_y;
    int                         circle_radius;
    int                         circle_speed;
    int                         v;
};
