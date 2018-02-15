#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ableton.setupLink(beatsPerMinute, 8.0);
    playModes.setup(ofxBenG::playmodes::c920, 1280, 720, 60);
    beatsPerMinute.addSubscriber([&]() { ableton.setBeatsPerMinute((int)beatsPerMinute); });
    propertyBag.add(CAST_PROPERTY(beatsPerMinute));
    propertyBag.loadFromXml();
    twister = new ofxBenG::twister();
    twister->bindToMultipleEncoders(&propertyBag);
    nextBeat = ableton.getBeat() + 10;
}

ofApp::ofApp() {}
ofApp::~ofApp() {
    propertyBag.saveToXml();
}

//--------------------------------------------------------------
void ofApp::update(){
    propertyBag.update();
    int seconds = ofGetElapsedTimef();
    bool isEvery = int(ableton.getBeat()) > nextBeat;
    if (isEvery) {
        static bool toggle = true;
        if (toggle) {
            std::cout << "switching to blackmagic" << std::endl;
            playModes.setup(ofxBenG::playmodes::blackmagic, 1280, 720, 59.94);
        } else {
            std::cout << "switching to c920" << std::endl;
            playModes.setup(ofxBenG::playmodes::c920, 1280, 720, 60);
        }
        toggle = !toggle;
        nextBeat += 2;
    }
    playModes.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    playModes.drawColumns(1);
    float y = 15;
    ofxBenG::utilities::drawLabelValue("beat", ableton.getBeat(), y);
    ofxBenG::utilities::drawLabelValue("bpm", ableton.getTempo(), y += 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
