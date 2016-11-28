#pragma once

#ifndef __ofxEasyFboGlitch__
#define __ofxEasyFboGlitch__

#include <iostream>

#include "ofMain.h"

#ifndef TARGET_OPENGLES
#include "ofxFastFboReader.h"
#endif
class ofxEasyFboGlitch : public ofBaseApp{
public:
    ofxEasyFboGlitch();

    //void setup();
    void allocate(float _w,float _h);
    void draw(ofFbo _fbo,float _x,float _y,float _w,float _h);
    void setGlichResetProbability (float _probability);

    ofImage glitchImg;
    ofImageQualityType imgQuality;
    float fboW,fboH;
    bool glitchReset;
    ofBuffer buffer;
    ofFbo fbo;
    ofPixels pix;
#ifndef TARGET_OPENGLES
    ofxFastFboReader reader;
#endif
    float glitchResetProbability;
};
#endif
