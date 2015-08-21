#pragma once
#include "ofMain.h"
#include "../Globales.h"


class cajaTexto {

	int ancho, largo;
	ofColor colorFondo, colorTexto;
public:

	cajaTexto() {};
	cajaTexto(int,int, string, ofColor, ofColor);

	void draw();

	string texto;
	ofFbo fbo;
	ofTrueTypeFont titulo;

};