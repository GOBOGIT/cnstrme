#pragma once
#include "ofMain.h"
#include "../globales.h"

#include "ofxAssimpModelLoader.h"
#include "../Gui/GuiEstaticos.h"
#include "../Gui//BtnCirculo.h"
#include "../Cajas/cajaTexto.h"
#include "../Cajas/cajaImagen.h"


class Principal {


public:

	Principal() {};
	~Principal() {};


	void draw(int _r, int _g, int _b);
	void update();

	void estados(bool);
	void activar();
	void desactivar();
	void iniciar();

	bool botonPanelActivo;

	ofEasyCam cam;
	ofxAssimpModelLoader modelo;
	ofLight iluminacion;

	boton botonPanel;

	GuiEstaticos guiEstatico;
	

	cajaTexto cajaTxt;
	cajaImagen cajaImg;
};