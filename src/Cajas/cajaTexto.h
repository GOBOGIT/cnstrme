#pragma once
#include "ofMain.h"
#include "../Globales.h"


class cajaTexto {

	int ancho, largo;

public:

	cajaTexto() {};
	cajaTexto(int,int, string);

	void draw();

	string texto;
	ofFbo fbo;
	ofTrueTypeFont titulo;

};