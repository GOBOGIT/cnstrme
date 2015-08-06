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
	void update(escena);
	void draw(float, float);
	void estados(bool,bool,bool);
	void animacion();

	


	int delay;
	int duration;
	int POSY;
	int LARGO;

	ofTrueTypeFont typo;
	boton BtnInicio;
	boton BtnRegresaInicio;
	boton BtnAyuda;
	escena escenaSel;

	ofxTween animGuiLinear;
	ofxEasingLinear easinglinear;
};