#include "cajaImagen.h"


cajaImagen::cajaImagen(int _largo, int _ancho, ofTexture _textura) {


	imagen = _textura;
	largo = _largo;
	ancho = _ancho;

	FboCajaImagen.allocate(largo,ancho,GL_RGBA);
	FboCajaImagen.begin();
	ofPushStyle();
		imagen.draw(0,0, largo, ancho);
	ofPopStyle();
	FboCajaImagen.end();
}



