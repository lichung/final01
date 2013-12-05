#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(30);
    
    ofAddListener(recognizer.speechRecognizedEvent, this, &testApp::speechRecognized);
    recognizer.initRecognizer();
    recognizer.loadDictionaryFromFile("dictionary.txt");
    recognizer.startListening();
    
    drawCircle      = false;
    light           = false;
    circle_x        = ofGetWidth()/2;
    circle_y        = ofGetHeight()/2;
    circle_radius   = 2;
    circle_speed    = 1;
    v = 70;
    
    //font.loadFont("Dreamer.ttf", 24);
    
    bugs.resize(200);
    for(auto& bug : bugs) {
        bug.setup();}
}

//--------------------------------------------------------------
void testApp::speechRecognized(string & wordRecognized)
{
    cout << wordRecognized << endl;
    if(wordRecognized == "time")
    {
        drawCircle =! drawCircle;
        
    }
    
    if(wordRecognized == "light")
    {
        light =! light;
        
    }

    
}

//--------------------------------------------------------------
void testApp::update(){
    for(auto& bug : bugs) {
        bug.update();
    }
     
    
     circle_radius += circle_speed;   
    
    
    if(circle_radius == 40){
       circle_speed = circle_speed * -1;
    }
    
    if(circle_radius == 2){
        circle_speed = circle_speed * -1;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0);
    
    if(drawCircle==true){
        
        //        ofColor(255,0,0);
        //        ofCircle(100, 100, 500);
        //ofCircle(circle_x, circle_y, circle_radius);
//        ofBackground(v);
        
        for(auto& bug : bugs) {
            bug.draw();
        }
        
        ofColor(255);
        ofCircle(circle_x - ofGetWidth()/2.0, circle_y - ofGetHeight()/2.0, 30);
    }
    
    if(light==true){
        ofColor(255);
        ofCircle(circle_x - ofGetWidth()/2.0, circle_y - ofGetHeight()/2.0, 100);
    }
    
    
    //    for(int i=1; i<13; i++)
    //    {
    //        float angle = ofMap(i, 0, 12, CLOCK_TOP, CLOCK_TOP+M_TWO_PI);
    //        float x = cos(angle) * 300;
    //        float y = sin(angle) * 300;
    //        font.drawString(ofToString(i), x, y);
    //    }
    
    ofPopMatrix();
    
    ofCircle(circle_x, circle_y, circle_radius);
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == 'l'){
        light =! light;
    }
    if (key == 't'){
        drawCircle =! drawCircle;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
//    circle_x = mouseX;
//    circle_y = mouseY;
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    drawCircle = false;
//    circle_radius ++;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}
