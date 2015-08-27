#include "ofApp.h"


//--------------------------------------------------------------

void ofApp::setup(){

	// carga assets
	globales.assets(); 

	// escenas
	escenaPrincipal.iniciar();
	escenaGaleria.iniciar();
	escenaInicial.iniciar();
	//varios
	//ofSetFrameRate(60);
	ofTrueTypeFont::setGlobalDpi(72);
	ofSetCircleResolution(64);

	// define la escena inicial
	escenas = inicio;
	escenaSel = inicio;
	//GUI escenas
	guiEscenas.setup();

	// inicializa titulo
	titulo = Titulo();

	activaCambioEscena =false;
	rafagaActivada = false;

}

//--------------------------------------------------------------
void ofApp::update(){


		if(escenaInicial.BtnInicio.getter() || guiEscenas.BtnInicio.getter()){
		
			selEscena(1);
			escenaInicial.BtnInicio.setter(false);
			guiEscenas.BtnInicio.setter(false);
				titulo.setter("Principal");
		}
		if(guiEscenas.BtnRegresaInicio.getter()){
			selEscena(0);
			guiEscenas.BtnRegresaInicio.setter(false);
		}
		if(guiEscenas.BtnGaleria.getter()){
			selEscena(2);
			titulo.setter("galeria");
			guiEscenas.BtnGaleria.setter(false);
		}
		guiEscenas.update();
		titulo.update();
		escenaGaleria.update();

	}


//--------------------------------------------------------------
void ofApp::draw(){


	cout << rafaga.iniciar;
	
	cout << rafaga.getter() << endl;


	// si se inicio la rafaga, esperar a que termine para cambiar de escena
	
//if(rafaga.iniciar && rafaga.getter()) { activaCambioEscena = true;}
	//else if(!rafaga.iniciar && rafaga.getter()) { activaCambioEscena = true;}
	// si no hay rafaga que mostrar	
//	else if((rafaga.iniciar) && rafaga.getter()) { activaCambioEscena = true;}


	switch(escenas) {
		case inicio:	escenaInicial.draw(200,200,200);	break;
		case principal:	escenaPrincipal.draw(230,230,230);	break;
		case galeria:	escenaGaleria.draw(230,230,230);	break;
	}


	if(escenas != inicio) {
		guiEscenas.draw(ofGetWidth()/2,ofGetHeight());
		titulo.draw();
	}

	// 1. aparece la rafaga
	// 2. Cambia la escena
	// 2. baja la rafaga
	
	//if(activarRafaga)

	rafaga.draw();


}


void ofApp::selEscena(int _numEscena) {
	
if(escenaSel !=_numEscena) {
	switch(_numEscena){
		case 0: escenas = inicio;
			rafagaActivada = false;	
			estadosEscenas(1,0,0);
			guiEscenas.estados(0,0,0,"inc");
			break;
		case 1: 
				rafagaActivada = true;	
				rafaga.estado(true);					// rafaga siempre cuando accedemos a principal
				escenas = principal ;						// cambia al terminar rafaga
				estadosEscenas(0,1,0);
				guiEscenas.estados(1,0,1,"pri");
			break;
		case 2: escenas = galeria; 
			rafagaActivada = false;	
	
			estadosEscenas(0,0,1);
			guiEscenas.estados(1,1,0,"gal");
			break;
	}
	escenaSel = escenas;
}
}

void ofApp::estadosEscenas(bool _a, bool _b, bool _c) {
	escenaInicial.estados(_a);
	_b? escenaPrincipal.activar() : escenaPrincipal.desactivar();
	escenaGaleria.estados(_c);
	
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
