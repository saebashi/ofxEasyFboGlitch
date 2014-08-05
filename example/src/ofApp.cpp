#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    fbo.allocate(ofGetWidth(),ofGetHeight());
    img.loadImage("of.png");
    ofSetFrameRate(60);

    //prepare for prepare------
    float r=ofGetWidth()*0.5;
    for (int i=0; i<10; i++) {
        ofVec3f newPos;
        newPos.set(ofRandomf()*r,ofRandomf()*r,ofRandomf()*r);
        pos.push_back(newPos);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    fbo.begin();
    ofBackground(ofColor::fromHsb(ofGetFrameNum()%255,255, 100));
    ofSetColor(255);
    ofPushMatrix();
    ofSetCircleResolution(3);
    ofTranslate(ofGetWidth()/2, ofGetWidth()/2);
    ofRotateX(ofGetFrameNum());
    ofRotateZ((float)ofGetFrameNum()/3);
    ofRotateY(-(float)ofGetFrameNum()/2);
    ofEnableDepthTest();
    for (int i=0; i<pos.size(); i++) {
        img.draw(pos[i].x, pos[i].y,pos[i].z, 200+500*(float)i/pos.size(),200+500*(float)i/pos.size());
    }
    fbo.end();
    ofPopMatrix();
    
    ofSetColor(255);
    
    fbo.draw(0, 0,ofGetWidth()/2,ofGetHeight()/2);
    //draw "fboGlitch" image
    fboGlitch.draw(fbo, ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight()/2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}