#pragma once
#include "ofMain.h"
#include "BtnCirculo.h"

class GuiEscenas {


private:

	float x, y;
	int largo;
	int ancho;
	bool estado;


public:

	void setup();
	void update();
	void draw(float, float);
	void estados(bool,bool,bool, string);
	void animacion();

	int delay;
	int duration;
	int POSY;
	int LARGO;

	string a,b;

	//ofTrueTypeFont typo;
	boton BtnInicio;
	boton BtnRegresaInicio;
	boton BtnAyuda;


	ofxTween animGuiLinear;
	ofxEasingLinear easinglinear;
};