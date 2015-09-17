#include "Rafaga.h"

Rafaga::Rafaga(float _duracion,  Contenedor &_contenedor, float _velocidad, ofColor _color) {
	
	duracion = _duracion;
	velocidad = _velocidad;
	// color de fondo
	color = _color;
	
	posyRafaga = ofGetWindowHeight();
	iniciar = false;
	finalizar = false;
	contenedor = &_contenedor;
	contenedor->estados(true);
	
}


void Rafaga::draw() {
	// animacion de entrada
	if(iniciar) {
		posyRafaga = anim.update();
		if(anim.isCompleted()){
			animSalida.setParameters(1,EasingSine,ofxTween::easeOut,0, ofGetWindowHeight(), velocidad,duracion);
			// finaliza la animacion de entrada
			finalizar = true;
			iniciar = false;
		}
	}

	if(finalizar){
		posyRafaga = animSalida.update();
		if(animSalida.isCompleted()) {
			contenedor->estados(false);
			finalizar = false;
		}
	}

	ofPushMatrix();
		ofPushStyle();
		ofTranslate(0,posyRafaga);
				ofFill();
				// color de fondo
				ofSetColor(color);
				// rectangulo que cubre la pantalla
				ofRect(0,0, ofGetWindowWidth(), ofGetWindowHeight());
				ofNoFill();
				// contenedor, CENTRADO
				contenedor->draw((ofGetWindowWidth()/2) - contenedor->largo/2,(ofGetWindowHeight()/2)-contenedor->anchoFinal/2);
		ofPopStyle();	
	ofPopMatrix();
	
}



void Rafaga::update() {}


void Rafaga::estado(bool _iniciar) {
		iniciar = true;
		contenedor->estados(true);
		anim.setParameters(1,EasingSine,ofxTween::easeOut, ofGetWindowHeight(), 0, velocidad,0);
}

bool Rafaga::getter() {
	return finalizar;
}