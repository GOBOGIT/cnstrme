#pragma once

#include "ofMain.h"
#include "../Gui/Boton.h"


class cajaBoton {

	int w;
	boton::tiposBotones tipoBtn;
	int radio;
	
	string titulo;
	string colorBtn;
	



public:


	cajaBoton(){};
	cajaBoton(unsigned int _posFila, int _w, int _h, int _radio, string _titulo, boton::tiposBotones _tipoBtn, string _colorBtn);
	cajaBoton(unsigned int _posFila, int _w, int _h,string _titulo,  boton _btn);

	boton btn;
	void draw(int, int);
	void update(int, int);
	void estados(bool);

	int h;
	unsigned int posFila;
	string id;

};