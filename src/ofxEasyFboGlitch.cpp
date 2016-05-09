#include "ofxEasyFboGlitch.h"

//--------------------------------------------------------------
ofxEasyFboGlitch::ofxEasyFboGlitch(){
    fboW=320;
    fboH=240;
    imgQuality=OF_IMAGE_QUALITY_WORST;
    fbo.allocate(fboW,fboH);
    glitchResetProbability=0.3;
    glitchReset=true;
}
//--------------------------------------------------------------
void ofxEasyFboGlitch::allocate(float _w,float _h){
    fboW=_w;
    fboH=_h;
    fbo.allocate(fboW,fboH);
}

//--------------------------------------------------------------
void ofxEasyFboGlitch::draw(ofFbo _fbo,float _drawX,float _drawY,float _drawW,float _drawH){
    fbo.begin();
    ofSetColor(255);
    ofBackground(0);
    _fbo.draw(0,0,fboW,fboH);
    fbo.end();
    if(glitchReset){
        reader.readToPixels(fbo, pix);
        glitchImg.setFromPixels(pix);
        glitchReset=false;
    }
    ofSaveImage(glitchImg.getPixels(),buffer,OF_IMAGE_FORMAT_JPEG,imgQuality);
    int fileSize=buffer.size();
    int whichByte=(int)ofRandom(fileSize);
    int whichBit=ofRandom(8);
    char bitMask=1 << whichBit;
    char* data=buffer.getData();
    data[whichByte] |= bitMask;
    glitchImg.load(buffer);
    if (ofRandom(1)<glitchResetProbability) {
        glitchReset=true;
    }
    glitchImg.draw(_drawX,_drawY,_drawW,_drawH);
}
//--------------------------------------------------------------
void ofxEasyFboGlitch::setGlichResetProbability (float _probability){
    glitchResetProbability=ofClamp(_probability,0,1);;
}
