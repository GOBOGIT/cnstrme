#pragma once

#include "ofMain.h"
#include "../Globales.h"
#include "../Gui/BtnCirculo.h"
#include "../Gui/GuiEstaticos.h"
#include "../Cajas/cajaAnim.h"
#include "../Cajas//cajaTexto.h"



class Ayuda {

	bool estado;

public:

	Ayuda() {};
	~Ayuda() {};


	void draw(int _r, int _g, int _b);
	void update();


	void iniciar();
	void estados(bool);

	ofVideoPlayer prueba;
	ofFbo fboPrueba;

	cajaAnim cajaVideo;
	cajaTexto cajaTxt;
	GuiEstaticos contenedorVideo;
	
};