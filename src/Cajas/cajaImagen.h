#pragma once
#include "ofMain.h"

class cajaImagen{


	int ancho, largo;

public:

	cajaImagen() {};
	cajaImagen(int,int, ofTexture);

	void draw();

	string texto;
	ofFbo FboCajaImagen;
	ofTexture imagen;


};