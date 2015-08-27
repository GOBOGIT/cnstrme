#include "Rafaga.h"

extern Globales globales;

Rafaga::Rafaga(float _duracion, float _velocidad, ofColor _color) {

	duracion = _duracion;
	velocidad = _velocidad;
	color = _color;
	
	posyRafaga = ofGetWindowHeight();
	iniciar = false;
	finalizar = false;
	
	cajaImg = cajaImagen(1000,500, globales.mockupImagen1000x500, 0);
	contenedor.fila(cajaImg);
	contenedor.setup(1000,500,"",false,false);
		
	contenedor.estados(true);
}


void Rafaga::draw() {

	if(iniciar) {
		posyRafaga = anim.update();
		if(anim.isCompleted()){
			animSalida.setParameters(1,EasingSine,ofxTween::easeOut,0, ofGetWindowHeight(), velocidad,duracion);
			finalizar = true;
			iniciar = false;
		}
	}

	if(finalizar){
		
		posyRafaga = animSalida.update();
		if(animSalida.isCompleted()) {
			finalizar = false;
		}
	}


	ofPushMatrix();
		ofPushStyle();
		ofTranslate(0,posyRafaga);
				ofFill();
				ofSetColor(color);
				ofRect(0,0, ofGetWindowWidth(), ofGetWindowHeight());
				ofNoFill();
				contenedor.draw((ofGetWindowWidth()/2) - contenedor.largo/2,(ofGetWindowHeight()/2)-contenedor.anchoFinal/2);
		ofPopStyle();	
	ofPopMatrix();
	
	
}



void Rafaga::update() {
}


void Rafaga::estado(bool _iniciar) {
		iniciar = true;
		anim.setParameters(1,EasingSine,ofxTween::easeOut, ofGetWindowHeight(), 0, velocidad,0);
}

bool Rafaga::getter() {
	return finalizar;
}