#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);

	for (int i = 0; i < 20; i++) {
		this->noise_sources[i] = ofRandom(10);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < 20; i++) {
		this->noise_sources[i] += 0.025;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	this->cam.begin();
	ofTranslate(18, 18);

	float tmp_noise_sources[20];
	for (int i = 0; i < 20; i++) {
		tmp_noise_sources[i] = this->noise_sources[i];
	}

	ofColor c;
	int index = 0;
	for (int x = -ofGetWidth() / 2; x < ofGetWidth() / 2; x += 36) {
		for (int y = -ofGetHeight(); y < ofGetHeight(); y += 36) {
			if (ofNoise(tmp_noise_sources[index]) > 0.5) {

				c.setHsb(ofMap(x, -ofGetWidth() / 2, ofGetWidth() / 2, 0, 255), 255, 255);
				ofSetColor(c, ofMap(ofNoise(tmp_noise_sources[index]), 0.5, 1.0, 32, 300));

				ofRect(ofVec3f(x, y, 0), 30, 30);
			}

			if(index % 2 == 0) {
				tmp_noise_sources[index] += 0.025;
			}
			else {
				tmp_noise_sources[index] -= 0.025;
			}
		}
		index += 1;
	}

	this->cam.end();
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
