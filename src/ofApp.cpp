#include "ofApp.h"


//--------------------------------------------------------------


void ofApp::setup(){

	cout << "entra ofApp" << endl;
	// variables del sistema
	ofSetVerticalSync(true);  
	ofSetFrameRate(60);
	ofTrueTypeFont::setGlobalDpi(72);
	ofSetCircleResolution(64);
	// carga assets
	globales.assets(); 

	//escenas



	//// inicializa contenedores para rafagas. Se declaran aqui ya que no es necesario que sean globales a la clase
	contenedor[0].fila(cajaAnim(0,200,200,Globales::videoPlayer["videoPrueba"]));
	contenedor[0].fila(cajaTexto(1,200,200,"hola", ofColor::red, ofColor::white));
	contenedor[0].setup(200,200,"", false,false);
	contenedor[1].fila(cajaImagen(0, 400,200, Globales::imagenes["mockup160x160"]));
	contenedor[1].fila(cajaTexto(1,400,100,"Rafaga2", ofColor::blue, ofColor::white));
	contenedor[1].setup(400,200,"", false,false);
	// contenedores de las rafagas
	ContenedoresRafagas.emplace("Rafaga2", move(contenedor[1]));
	ContenedoresRafagas.emplace("Rafaga1", move(contenedor[0]));
	
	//// inicializa rafaga
	rafagas.emplace("rafaga1", move(Rafaga(2000, ContenedoresRafagas["Rafaga1"])));
	rafagas.emplace("rafaga2", move(Rafaga(2000, ContenedoresRafagas["Rafaga2"])));
	rafagas["rafaga1"].estado(true);

	// escenas
	escenaPrincipal.setup();
	escenaPrincipal.titulo="Principal";
	escenaGaleria.setup();
	escenaPrincipal.titulo ="Galeria";
	loop.setup();
	loop.titulo ="Loop";
	loop.estados(true);

	// define la escena inicial
	escenas = inicio;
	escenaSel = inicio;
	//GUI escenas
	guiEscenas.setup();

	// inicializa titulo
	titulo = Titulo();

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


	// añade el menu inferior
	if(escenas != inicio) {
		guiEscenas.draw(ofGetWidth()/2,ofGetHeight());
		titulo.draw();
	}

	
	if(iniciaRafaga) {
		RafagaSel.draw();
		if(RafagaSel.anim.isCompleted()) {
			escenas = escenaRafaga;	
			titulo.setter(tituloEscena);
			if(RafagaSel.animSalida.isCompleted())	{
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
				rafaga(inicio, tituloEscena);	
				break;
			case 1: 
				estadosEscenas(0,1,0);
				guiEscenas.estados(1,0,1);
				rafaga(rafagas["rafaga1"],principal, tituloEscena);	
				break;
			case 2:
				estadosEscenas(0,0,1);
				guiEscenas.estados(1,1,0);
				rafaga(galeria, tituloEscena);	
				break;
		}
	
	}
}

void ofApp::estadosEscenas(bool _a, bool _b, bool _c) {
	loop.estados(_a);
	escenaPrincipal.estados(_b);
	escenaGaleria.estados(_c);
}

void ofApp::rafaga(esc _esc, string _titulo) {
	escenas = _esc;
	titulo.setter(tituloEscena);
	escenaSel = _esc;
}

void ofApp::rafaga(Rafaga _rafaga, esc _esc, string _titulo) {
	iniciaRafaga = true;	
	RafagaSel = _rafaga;
	RafagaSel.estado(true);
	escenaRafaga = _esc;
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
