#pragma once

#include "ofMain.h"
#include "ofxBenG.h"

class ofApp : public ofBaseApp {

public:
    ofApp();~ofApp();
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofxBenG::playmodes playModes;
    ofxBenG::ableton ableton;
    ofxBenG::property_bag propertyBag;
    ofxBenG::property<float> beatsPerMinute = {"beatsPerMinute", 60, 0, 480};
    int nextBeat = 0;
    ofxBenG::twister* twister;
};