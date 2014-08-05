#pragma once

#ifndef __ofxEasyFboGlitch__
#define __ofxEasyFboGlitch__

#include <iostream>

#include "ofMain.h"
#include "ofxFastFboReader.h"
class ofxEasyFboGlitch : public ofBaseApp{
public:
    ofxEasyFboGlitch();

    //void setup();
    void draw(ofFbo _fbo,float _x,float _y,float _w,float _h);
    
    ofImage glitchImg;
    ofImageQualityType imgQuality;
    float fboW,fboH;
    bool glitchReset;
    ofFbo fbo;
    ofPixels pix;
    ofxFastFboReader reader;
};
#endif
