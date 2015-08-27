#include "Titulo.h"

// desde extern ofApp
extern Globales globales;

Titulo::Titulo() {

	posActual = 0;
	iniciaAnim = false;
	stack = "";
	textoTitulo = "GALERIA\nPRINCIPAL";
	titulo = globales.typoTitulo;
	titulo.setLineHeight(120);
	anchoFbo = 85;
	anchoLinea = 5;
	
}

void Titulo::update() {
	if(iniciaAnim) {
		desplazamiento = animacionTitulo.update();
		if(animacionTitulo.isCompleted()) {
			iniciaAnim = false;
		}
	}
		fboContenido();
}

void Titulo::draw() {
	FboCaja.draw(0,0);
}


void Titulo::fboContenido() {
	

	
	FboCaja.allocate(500,anchoFbo,GL_RGBA);
	FboCaja.begin();
	ofPushMatrix();
		ofPushStyle();
		ofSetColor(ofColor::black);
		titulo.drawString(textoTitulo,20,desplazamiento);
		ofRect(0,anchoFbo - anchoLinea, 50,anchoLinea);
		ofPopStyle();
	ofPopMatrix();
	FboCaja.end();
}


void Titulo::animacion() {
	animacionTitulo.setParameters(1,easing,ofxTween::easeOut, posActual,posFinal,200,0);
}

void Titulo::setter(string _titulo) {

	if(_titulo != stack){
		if(_titulo  == "Principal") posFinal = -50;
		if(_titulo  == "Galeria") posFinal = 70;
	
	iniciaAnim = true;
	animacion();
	stack = _titulo;
	}

}