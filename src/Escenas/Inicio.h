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
	

	void iniciar();
	void estados(bool);

	bool click;
	bool getter();
	void setter(bool);

	unsigned delay;
	unsigned duration;


	boton BtnInicio;
	ofTrueTypeFont typo;

	ofxTween animImagenInicio;
	ofxEasingElastic easingelastic;

	
};