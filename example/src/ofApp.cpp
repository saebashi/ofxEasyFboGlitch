#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    fbo.allocate(ofGetWidth(),ofGetHeight());
    img.loadImage("of.png");
    ofSetFrameRate(60);
    
    fboGlitch.allocate(320, 240);
    //prepare for prepare------
    float r=ofGetWidth()*0.3;
    for (int i=0; i<25; i++) {
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
    ofBackground(ofColor::fromHsb(ofGetFrameNum()%255,100, 200));
    ofSetColor(255);
    ofPushMatrix();
    ofSetCircleResolution(3);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateX(ofGetFrameNum());
    ofRotateZ((float)ofGetFrameNum()/3);
    ofRotateY(-(float)ofGetFrameNum()/2);
    ofEnableDepthTest();
    ofEnableNormalizedTexCoords();
    img.bind();
    ofSetColor(255);
    ofDrawBox(0, 0, 0, 200);
    for (int i=0; i<pos.size(); i++) {
        ofSetColor(ofColor::fromHsb(255*(float)i/pos.size(),150, 255));
        ofPushMatrix();
        ofRotateZ(ofGetFrameNum()*(float)i/pos.size());
        ofRotateY((float)ofGetFrameNum()/3*(float)i/pos.size());
        ofRotateX(-(float)ofGetFrameNum()/2*(float)i/pos.size());        ofTranslate(pos[i].x, pos[i].y,pos[i].z);
        ofDrawBox(0, 0, 0, 50+100*(float)i/pos.size());
        ofPopMatrix();
    }
    img.unbind();
    
    ofDisableNormalizedTexCoords();
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