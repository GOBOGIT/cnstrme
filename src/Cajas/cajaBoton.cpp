#include "cajaBoton.h"



// RECTANGULOS
cajaBoton::cajaBoton(unsigned int _posFila, int _w, int _h, ofImage _imagen, boton &_btn) {
	w = _w;
	h = _h;
	posFila = _posFila;
	imagen = _imagen;
	id = ofToString(rand());		// crea un id propio a cada boton de forma aleatoria
	btn = &_btn;

}
cajaBoton::cajaBoton(unsigned int _posFila, int _w, int _h, string _titulo, boton &_btn) {
	w = _w;
	h = _h;
	posFila = _posFila;
	titulo = _btn.texto;
	id = ofToString(rand());		// crea un id propio a cada boton de forma aleatoria
	btn = &_btn;
	titulo = _titulo;
}

// CIRCULO
cajaBoton::cajaBoton(unsigned int _posFila, int _w, int _h, int _r, ofImage _imagen, boton &_btn) {
	w = _w;
	h = _h;
	radio = _r;
	posFila = _posFila;
	imagen = _imagen;
	id = ofToString(rand());		// crea un id propio a cada boton de forma aleatoria
	btn = &_btn;
}
cajaBoton::cajaBoton(unsigned  int _posFila, int _w, int _h, int _r, string _titulo, boton &_btn) {
	w = _w;
	h = _h;
	radio = _r;
	posFila = _posFila;
	titulo = _titulo;
	id = ofToString(rand());		// crea un id propio a cada boton de forma aleatoria
	btn = &_btn;
}


void cajaBoton::draw(int _x, int _y) {
	ofPushMatrix();
		switch(btn->tipoBoton){
		case boton::circuloImagen:	btn->draw(ofVec2f(w-(w/2)+_x, h-(h/2)+_y), radio, Globales::iconos["icoGaleria"]); break;
		case boton::circuloTexto:	btn->draw(ofVec2f(w-(w/2)+_x, h-(h/2)+_y),radio, titulo); break;
		
		case boton::rectImagen: btn->draw(ofVec2f(_x,_y),w,h, imagen); break;
		case boton::rectTexto: btn->draw(ofVec2f(_x,_y),w,h, titulo); break;
		}
	ofPopMatrix();
}

void cajaBoton::update( int _x, int _y) {
	//btn.update(_x,_y);

}


void cajaBoton::estados(bool _estado) {

	if(_estado){
		btn->estados(true);
	} else {
		btn->estados(false);
	}

}