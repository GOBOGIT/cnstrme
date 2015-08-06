#include "ofApp.h"


//--------------------------------------------------------------

void ofApp::setup(){

	
	// escenas
	escenaPrincipal.iniciar();
	escenaAyuda.iniciar();
	escenaInicial.iniciar();
	//varios
	ofSetFrameRate(60);
	ofTrueTypeFont::setGlobalDpi(72);
	ofSetCircleResolution(64);

	// define la escena inicial
	escenas = inicio;	 
	escenaSel = inicio;	


	//GUI escenas
	guiEscenas.setup();

}

//--------------------------------------------------------------
void ofApp::update(){

	if(escenaSel !=escenas) {
		switch(escenas) {
			case inicio:	estadosEscenas(1,0,0);	break;
			case principal:	estadosEscenas(0,1,0);	break;
			case ayuda:		estadosEscenas(0,0,1);	break;
		}
	
		escenaSel = escenas;
	}
	guiEscenas.update(escenas);

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	switch(escenas) {
		case inicio:	escenaInicial.draw(230,230,230);	break;
		case principal:	escenaPrincipal.draw(230,230,230);	break;
		case ayuda:		escenaAyuda.draw(230,230,230);		break;
	}

	if(escenas != inicio)	guiEscenas.draw(ofGetWidth()/2,ofGetHeight());
}


void ofApp::estadosEscenas(bool _a, bool _b, bool _c) {
	escenaInicial.estados(_a);
	escenaPrincipal.estados(_b);
	escenaAyuda.estados(_c);
}


void ofApp::keyPressed(int key){}
void ofApp::keyReleased(int key){}

void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}

void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){ }
