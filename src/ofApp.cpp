#include "ofApp.h"


//--------------------------------------------------------------

void ofApp::setup(){

	// carga assets
	globales.assets(); 

	// escenas
	escenaPrincipal.iniciar("Principal");
	escenaGaleria.iniciar("Galeria");
	loop.iniciar("Inicio");
	loop.estados(true);
	//varios
	ofSetFrameRate(60);
	ofTrueTypeFont::setGlobalDpi(72);
	ofSetCircleResolution(64);

	// define la escena inicial
	escenas = inicio;
	escenaSel = inicio;
	//GUI escenas
	guiEscenas.setup();

	// inicializa titulo
	titulo = Titulo();

	// inicializa rafaga
	animRafaga = Rafaga(2000);
	iniciaRafaga = false;


}

//--------------------------------------------------------------
void ofApp::update(){


		if(loop.BtnInicio.getter()){
			loop.BtnInicio.setter(false);
			selEscena(1, escenaPrincipal.titulo);
		}
		if(guiEscenas.BtnInicio.getter()){
			guiEscenas.BtnInicio.setter(false);
				selEscena(1, escenaPrincipal.titulo);
		}
		if(guiEscenas.BtnRegresaInicio.getter()){
			selEscena(0, loop.titulo);
			guiEscenas.BtnRegresaInicio.setter(false);
		}
		if(guiEscenas.BtnGaleria.getter()){
			selEscena(2, escenaGaleria.titulo);
			guiEscenas.BtnGaleria.setter(false);
		}
		guiEscenas.update();
		titulo.update();
		escenaGaleria.update();
		escenaPrincipal.update();

}


//--------------------------------------------------------------
void ofApp::draw(){



	switch(escenas) {
		case inicio:	loop.draw(200,200,200);	break;
		case principal:	escenaPrincipal.draw(230,230,230);	break;
		case galeria:	escenaGaleria.draw(230,230,230);	break;
	}


	if(escenas != inicio) {
		guiEscenas.draw(ofGetWidth()/2,ofGetHeight());
		titulo.draw();
	}

	
	if(iniciaRafaga) {
		animRafaga.draw();
		if(animRafaga.anim.isCompleted()) {
			escenas = escenaRafaga;	
			titulo.setter(tituloEscena);
			if(animRafaga.animSalida.isCompleted())	{
				iniciaRafaga = false;
			
			}
		}
	}

	
	ofDrawBitmapString(ofToString(ofGetFrameRate()),10,10,0);

}


void ofApp::selEscena(int _numEscena, string _titulo) {

tituloEscena = _titulo;
if(escenaSel !=_numEscena) {
	switch(_numEscena){
		case 0: 
			estadosEscenas(1,0,0);
			guiEscenas.estados(0,0,0);
			rafaga(false,inicio, tituloEscena);	
			break;
		case 1: 
			estadosEscenas(0,1,0);
			guiEscenas.estados(1,0,1);
			//guiEscenas.animacion();
			rafaga(false,principal, tituloEscena);	
			break;
		case 2:
			estadosEscenas(0,0,1);
			guiEscenas.estados(1,1,0);
			rafaga(false,galeria, tituloEscena);	
			break;
	}
	
}
}

void ofApp::estadosEscenas(bool _a, bool _b, bool _c) {
	loop.estados(_a);
	_b? escenaPrincipal.activar() : escenaPrincipal.desactivar();
	escenaGaleria.estados(_c);
	
}


void ofApp::rafaga(bool _rafaga, esc _esc, string _titulo) {
	if(_rafaga){	
		iniciaRafaga = true;
		animRafaga.estado(true);
		escenaRafaga = _esc;
	} else {
		escenas = _esc;
		titulo.setter(tituloEscena);
	}
		escenaSel = _esc;
		
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
