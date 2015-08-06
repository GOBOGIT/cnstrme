#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "../Gui/GuiEstaticos.h"




class Principal {


public:

	Principal() {};
	~Principal() {};


	void draw(int _r, int _g, int _b);

	void estados(bool);
	void iniciar();

	ofEasyCam cam;
	ofxAssimpModelLoader modelo;

	GuiEstaticos guiEstatico;
};