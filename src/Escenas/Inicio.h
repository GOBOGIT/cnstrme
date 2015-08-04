#pragma once
#include "ofMain.h"
#include "ofEvents.h"
#include "../Gui/BtnCirculo.h"



class Inicio {

private:
	
	ofTexture imagen;

public:

	Inicio() {};
	~Inicio() {};
	
	void draw(int _r, int _g, int _b);
	
	void desactivar();
	void activar();
	void iniciar();

	unsigned delay;
	unsigned duration;


	boton BtnInicio;
	ofTrueTypeFont typo;

	ofxTween animImagenInicio;
	ofxEasingElastic easingelastic;

	
};