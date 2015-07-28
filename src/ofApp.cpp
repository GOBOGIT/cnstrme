#include "ofApp.h"




//--------------------------------------------------------------
void ofApp::setup(){
		
	//!! cambiar nombre del metodo como CARGA_RECURSOS
		escenaInicial.ImagenInicio();
		escenas = inicio;
}

//--------------------------------------------------------------
void ofApp::update(){


}

//--------------------------------------------------------------
void ofApp::draw(){
	
	switch(escenas) {
		case inicio: 
			escenaInicial.draw(200,10,10);
			break;
		case principal:
			escenaPrincipal.draw(10,200,10);
			break;	
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key =='a'){
		switch(escenas) {
			case inicio: escenas = principal;break;
			case principal: escenas = inicio;break;	
		}
	}
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
