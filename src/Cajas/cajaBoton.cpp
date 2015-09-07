#include "cajaBoton.h"

cajaBoton::cajaBoton(unsigned int _posFila, int _w, int _h, int _radio, string _titulo, boton::tiposBotones _tipoBtn, string _colorBtn) {
	w = _w;
	h = _h;
	titulo = _titulo;
	colorBtn = _colorBtn;
	tipoBtn = _tipoBtn;
	radio = _radio;
	posFila = _posFila;
	id = ofToString(rand());		// crea un id propio a cada boton de forma aleatoria
	btn = boton(tipoBtn, colorBtn);		// titulo, [circulo/rectangulo], color
}

cajaBoton::cajaBoton(unsigned int _posFila, int _w, int _h, string _titulo, boton _btn) {
	w = _w;
	h = _h;
	posFila = _posFila;
	titulo = _titulo;
	id = ofToString(rand());		// crea un id propio a cada boton de forma aleatoria
	btn = _btn;

}


void cajaBoton::draw(int _x, int _y) {
	ofPushMatrix();
	if(btn.tipoBoton == boton::circuloTexto)
		btn.draw(ofVec2f(w-(w/2)+_x, h-(h/2)+_y),50, titulo);
	ofPopMatrix();
}

void cajaBoton::update( int _x, int _y) {
	btn.update(_x,_y);
}




void cajaBoton::estados(bool _estado) {

	if(_estado){
		btn.estados(true);
	} else {
		btn.estados(false);
	}

}