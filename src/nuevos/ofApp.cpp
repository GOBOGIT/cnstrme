#include "ofApp.h"


//--------------------------------------------------------------

void ofApp::setup(){

	// carga assets
	globales.assets(); 

	// escenas
	st_principal.escenaPrincipal.iniciar();
	st_galeria.escenaGaleria.iniciar();
	st_inicio.escenaInicial.iniciar();
	//varios
	//ofSetFrameRate(60);
	ofTrueTypeFont::setGlobalDpi(72);
	ofSetCircleResolution(64);


	//GUI escenas
	guiEscenas.setup();

	// inicializa titulo
	titulo = Titulo();

	st_inicio.rafaga = false;
	st_inicio.estadosEscenas[3]=(1,0,0);
	st_inicio.estadosBotones[3] =(0,0,0);
	st_inicio.nombre = "inicio";
	st_inicio.enumEscena = inicio;

	st_principal.rafaga = true;
	st_principal.estadosEscenas[3] = (0,1,0);
	st_principal.estadosBotones[3] =(1,0,1);
	st_principal.nombre ="principal";
	st_principal.enumEscena = principal;
	
	st_galeria.rafaga = false;
	st_galeria.estadosEscenas[3] = (0,0,1);
	st_galeria.estadosBotones[3] =(1,1,0);
	st_galeria.nombre ="galeria";
	st_galeria.enumEscena = galeria;

	// define la escena inicial
	escenas = st_inicio.enumEscena;
	escenaSel = st_inicio.enumEscena;

}

//--------------------------------------------------------------
void ofApp::update(){


		if(st_inicio.escenaInicial.BtnInicio.getter() || guiEscenas.BtnInicio.getter()){
			selEscena(st_principal);
			st_inicio.escenaInicial.BtnInicio.setter(false);
			guiEscenas.BtnInicio.setter(false);
			titulo.setter(st_principal.nombre);
		}
		if(guiEscenas.BtnRegresaInicio.getter()){
			selEscena(st_inicio);
			guiEscenas.BtnRegresaInicio.setter(false);
		}
		if(guiEscenas.BtnGaleria.getter()){
			selEscena(st_galeria);
			titulo.setter(st_galeria.nombre);
			guiEscenas.BtnGaleria.setter(false);
		}
		guiEscenas.update();
		titulo.update();
		st_galeria.escenaGaleria.update();

	}


//--------------------------------------------------------------
void ofApp::draw(){

	switch(escenas) {
		case inicio:	st_inicio.escenaInicial.draw(200,200,200);	break;
		case principal:	st_inicio.escenaPrincipal.draw(230,230,230);	break;
		case galeria:	st_inicio.escenaGaleria.draw(230,230,230);	break;
	}


	if(escenas != inicio) {
		guiEscenas.draw(ofGetWidth()/2,ofGetHeight());
		titulo.draw();
	}
}


void ofApp::selEscena(escena _escena) {

	if(esceSel.enumEscena != _escena.enumEscena) {

		escenas= _escena.enumEscena;

		estadosEscenas(
			_escena.estadosEscenas[0],
			_escena.estadosEscenas[1],
			_escena.estadosEscenas[2]);
		
		guiEscenas.estados(
			_escena.estadosBotones[0],
			_escena.estadosBotones[1],
			_escena.estadosBotones[2],
			_escena.nombre);
		
		esceSel.enumEscena = _escena.enumEscena;
	}
}

/*
void ofApp::selEscena(int _numEscena) {


if(escenaSel !=_numEscena) {
	switch(_numEscena){
		case 0: escenas = inicio;
			estadosEscenas(1,0,0);
			guiEscenas.estados(0,0,0,"inc");
			break;
		case 1: 
				escenas = principal ;
				estadosEscenas(0,1,0);
				guiEscenas.estados(1,0,1,"pri");
			break;
		case 2: escenas = galeria; 
			estadosEscenas(0,0,1);
			guiEscenas.estados(1,1,0,"gal");
			break;
	}
	escenaSel = escenas;
}
}*/

void ofApp::estadosEscenas(bool _a, bool _b, bool _c) {
	st_inicio.escenaInicial.estados(_a);
	_b? st_principal.escenaPrincipal.activar() : st_principal.escenaPrincipal.desactivar();
	st_galeria.escenaGaleria.estados(_c);
	
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
