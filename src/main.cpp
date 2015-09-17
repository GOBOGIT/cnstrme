#include "ofApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){
	//ofAppGlutWindow window; // create a window

	//window.setDoubleBuffering(true);
	//window.setGlutDisplayString("rgba double samples>=1 ");
	// res 1080 * 0.8 1536,864
	ofSetupOpenGL(1536,864,OF_WINDOW);	
	//ofSetupOpenGL(1920,1080,OF_FULLSCREEN);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
