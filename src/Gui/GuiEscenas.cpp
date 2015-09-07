#include "GuiEscenas.h"

#define DELAY 20.
#define DURATION 300.

void GuiEscenas::setup() {

	//tween
	estado =true;
	POSY = 100;
	LARGO = 300;

	estados(0,0,0);

	//botones
	BtnInicio= boton(boton::circuloTexto, "verde");
	BtnRegresaInicio= boton(boton::circuloTexto,"verde");
	BtnGaleria= boton(boton::circuloImagen,"verde");

}

void GuiEscenas::draw(float _x, float _y) {

	
	// posicion de la caja
	x = _x - LARGO / 2;
	if(!estado) 
		y = _y - POSY;
	else {
		y = _y - animGuiLinear.update();
		if(	animGuiLinear.isCompleted())	estado = false;
	}

	ofPushMatrix();
			BtnRegresaInicio.draw(ofVec2f(0,0),50, "INICIO");
			BtnInicio.draw(ofVec2f(150,0),50, "ESCENA 3D");
			BtnGaleria.draw(ofVec2f(300,0),100, Globales::iconos["icoGaleria"]);
	ofPopMatrix();

}

void GuiEscenas::update() {
	BtnRegresaInicio.update(x,y);
	BtnInicio.update(x,y);
	BtnGaleria.update(x,y);
}

void GuiEscenas::animacion() {
	estado = true;
	//animacion();
	animGuiLinear.setParameters(2,easinglinear,ofxTween::easeOut, 0,POSY,DURATION, DELAY);
}

void GuiEscenas::estados(bool _a, bool _b, bool _c) {
	BtnRegresaInicio.estados(_a);
	BtnInicio.estados(_b);
	BtnGaleria.estados(_c);
}


