#pragma once
#include "ofMain.h"

class cajaImagen{


	int ancho, largo;

public:

	cajaImagen() {};

	/** Parámetros
	@param ancho y largo para allocate del fbo
	@param textura a insertar en fbo
	@param posicion de arriba a abajo en contenedor */
	cajaImagen(int,int, ofTexture, unsigned int);

	void draw();
	void update();
	void estados(bool);

	string texto;
	ofFbo fbo;
	ofTexture imagen;

	int h;
	unsigned int posFila;
};