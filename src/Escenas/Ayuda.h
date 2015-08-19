#pragma once
#include "ofMain.h"
#include "ofEvents.h"
#include "../Gui/BtnCirculo.h"
#include "../interface.h"


class Ayuda {


public:

	Ayuda() {};
	~Ayuda() {};


	void draw(int _r, int _g, int _b);

	void desactivar();
	void activar();
	void iniciar();
	
	boton BtnRegresaPrincipal;


};