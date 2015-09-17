#pragma once

#include "ofMain.h"
#include "../Gui/Boton.h"


class cajaBoton {

	int w;
	boton::tiposBotones tipoBtn;
	int radio;
	
	string titulo;
	string colorBtn;
	ofImage imagen;

public:


	cajaBoton(){};
	cajaBoton(unsigned int _posFila, int _w, int _h, ofImage _imagen, boton &_btn);	// rectangulo imagen
	cajaBoton(unsigned int _posFila, int _w, int _h, string _titulo, boton &_btn);	// rectangulo imagen
	cajaBoton(unsigned int _posFila, int _w, int _h, int _r, ofImage _imagen, boton &_btn);			// circulo
	cajaBoton(unsigned int _posFila, int _w, int _h, int _r, string _titulo, boton &_btn);	
	
	boton *btn;
	void draw(int, int);
	void update(int, int);
	void estados(bool);

	int h;
	unsigned int posFila;
	string id;

};