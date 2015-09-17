#pragma once
#include "ofMain.h"

class cajaImagen{

	int ancho, largo;
	ofImage imagen;

public:

	cajaImagen() {};

	/** Parámetros
	@param posicion de arriba a abajo en contenedor 
	@param ancho y largo para allocate del fbo
	@param textura a insertar en fbo */
	cajaImagen(unsigned int, int,int, ofImage);

	void draw();
	void update();
	/** todas las cajas deben llevar estados(bool) por compatibilidad en llamadas desde contenedor */
	void estados(bool);

	//string texto;

	/** regresa FBO del vídeo 
	@return devuelve fbo
	*/
	ofFbo fbo;

	/** @param devuelve altura */
	int h;
	/** @param devuelve la posicion en el contenedor*/
	unsigned int posFila;
};