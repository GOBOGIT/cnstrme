#include "ofMain.h"
#include "ofApp.h"



//========================================================================
int main( ){
	// res 1080 * 0.8
	ofSetupOpenGL(1536,864,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
