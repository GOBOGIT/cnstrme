#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "../Gui/BtnCirculo.h"



class Principal {


public:

	Principal() {};
	~Principal() {};


	void draw(int _r, int _g, int _b);

	void desactivar();
	void activar();
	void iniciar();


	boton BtnRegresaInicio;
	boton BtnAyuda;
	ofTrueTypeFont typo;

	ofEasyCam cam;
	ofxAssimpModelLoader modelo;

};