#include "ofApp.h"

escena escenas;

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
}

//--------------------------------------------------------------
void ofApp::update(){

	if(escenaSel !=escenas) {
		switch(escenas) {
			case inicio:
				escenaInicial.activar();
				escenaPrincipal.desactivar();
				 break;
			case principal:
				cout << "entrainicio" <<endl;
				escenaInicial.desactivar();
				escenaAyuda.desactivar();
				escenaPrincipal.activar();
				break;
			case ayuda:
				escenaPrincipal.desactivar();
				escenaAyuda.activar();
				break;
		}
		escenaSel = escenas;
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	switch(escenas) {
		case inicio: 
			escenaInicial.draw(230,230,230); 
			break;
		case principal: 
			escenaPrincipal.draw(230,230,230);
			break;
		case ayuda: escenaAyuda.draw(230,230,230);
			break;
	}
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
