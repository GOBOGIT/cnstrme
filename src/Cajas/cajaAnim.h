#pragma once
#include "ofMain.h"

class cajaAnim{

	int ancho, largo;
	ofLoopType tipoLoop;

public:

	cajaAnim() {};
	
	/** constructor cajaAnim
	@param (pos en Contenedor, posx, posy,  video ya cargado desde load, tipo de loop (defecto:OF_LOOP_NONE) */
	cajaAnim(unsigned int, int,int, ofVideoPlayer*, ofLoopType = OF_LOOP_NONE);

	/** dibuja la caja dentro del fbo */
	void draw();
	
	/** colocar siempre en update de escena para refrescar video */
	void update();

	/** todas las cajas deben llevar estados(bool) por compatibilidad en llamadas desde contenedor */
	void estados(bool);
	/** regresa FBO del vídeo 
	@return devuelve fbo
	*/
	ofFbo fbo;
	/** se debe acceder para poder modificar sus propiedades
	@return devuelve el video tipo ofVideoPlayer */
	ofVideoPlayer* video;

	/** @param devuelve altura */
	int h;
	/** @param devuelve la posicion en el contenedor*/
	unsigned int posFila;
	


};



