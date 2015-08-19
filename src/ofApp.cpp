#include "ofApp.h"
#include "interface.h"

escena escenas;

//--------------------------------------------------------------

void ofApp::setup(){
	
	escenaPrincipal.iniciar();
	escenaAyuda.iniciar();
	escenaInicial.iniciar();

	ofSetFrameRate(60);
	escenas = inicio;
	escenaSel = inicio;	
}

//--------------------------------------------------------------
void ofApp::update(){

	if(escenaSel !=escenas) {
		switch(escenas) {
			case inicio: break;
				escenaInicial.activar();
				escenaPrincipal.desactivar();
			case principal:
				escenaInicial.desactivar();
				escenaAyuda.desactivar();
				escenaPrincipal.activar();
				break;
			case ayuda:
				escenaPrincipal.desactivar();
				escenaAyuda.activar();
				break;
		}
		cout << "if" << endl;
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
			escenaPrincipal.draw(200,10,10);
			break;
		case ayuda: escenaAyuda.draw(100,10,10);
			break;

	}
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
