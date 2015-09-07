#pragma once
#include "ofMain.h"
#include "../Globales.h"


class cajaTexto {

	int ancho, largo;
	ofColor colorFondo, colorTexto;
	string texto;
	ofTrueTypeFont titulo;

	public:

	cajaTexto() {};

	/** parámetros de entrada
	@param ancho y largo para allocate
	@param texto a mostrar
	@param color de fondo
	@param color de texto
	@param orden de arriba a abajo en contenedor */
	cajaTexto(unsigned int,int,int, string, ofColor, ofColor);

	void draw();
	void update() {};
	void estados(bool) {};


	ofFbo fbo;
	int h;
	unsigned int posFila;

};