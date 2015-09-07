#pragma once
#include "ofMain.h"
#include "Boton.h"

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
	void estados(bool,bool,bool);
	void animacion();

	int POSY;
	int LARGO;


	//ofTrueTypeFont typo;
	boton BtnInicio;
	boton BtnRegresaInicio;
	boton BtnGaleria;


	ofxTween animGuiLinear;
	ofxEasingLinear easinglinear;
};