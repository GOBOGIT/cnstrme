#pragma once
#include "ofMain.h"
#include "../Escena.h"


class Loop : public Escena {

private:
	
	ofImage imagen;
	ofxTween animImagenInicio;
	ofxEasingElastic easingelastic;
	ofxHapPlayer* videoF;

public:

	Loop(){};
	~Loop(){};
	
	void draw(int _r, int _g, int _b);
	void setup();
	void estados(bool);

	unsigned delay;
	unsigned duration;

	boton BtnInicio;
	
	
};