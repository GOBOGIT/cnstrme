#include "cajaImagen.h"


cajaImagen::cajaImagen(int _largo, int _ancho, ofImage _textura, unsigned int _posFila) {


	imagen = _textura;
	largo = _largo;
	ancho = _ancho;
	h = ancho;
	posFila = _posFila;

	fbo.allocate(largo,ancho,GL_RGBA);
	fbo.begin();
	ofPushMatrix();
		ofPushStyle();
		imagen.draw(0,0, largo, ancho);
		ofPopStyle();
	ofPopMatrix();
	
	fbo.end();
}

void cajaImagen::draw() {

	fbo.draw(0,0);
}



