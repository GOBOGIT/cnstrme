#pragma once
#include "ofMain.h"
//#include "ofEvents.h"
#include "../Gui/Boton.h"

class Inicio {

private:
	
	ofTexture imagen;
	ofxTween animImagenInicio;
	ofxEasingElastic easingelastic;
	ofTrueTypeFont typo;

public:

	Inicio(){};
	~Inicio() {};
	
	void draw(int _r, int _g, int _b);
	

	void iniciar(string);
	void estados(bool);

	bool click;
	bool getter();
	void setter(bool);

	unsigned delay;
	unsigned duration;

	string titulo;
	boton BtnInicio;
	



	
};