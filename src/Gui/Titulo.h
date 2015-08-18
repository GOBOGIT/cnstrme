#pragma once
#include "ofMain.h"
#include "../Globales.h"
#include "ofxTween.h"

class Titulo {

private:

	int x,y;
	int posActual, posFinal;
	int anchoFbo;
	int anchoLinea;

public:

	Titulo();
	
	void draw();
	void update();
	void fboContenido();
	void animacion();
	void setter(string);

	float desplazamiento;
	bool iniciaAnim;

	ofTrueTypeFont titulo;
	string textoTitulo;
	string stack;

	ofFbo FboCaja;

	ofxTween animacionTitulo;
	ofxEasingBack easing;

	

};