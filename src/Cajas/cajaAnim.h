#pragma once
#include "ofMain.h"

class cajaAnim{

	int ancho, largo;

public:

	cajaAnim() {};
	
	/** constructor cajaAnim
	@param (posx, posy,  video ya cargado desde load) */
	cajaAnim(int,int, ofVideoPlayer);

	/** dibuja la caja dentro del fbo */
	void draw();
	
	/** colocar siempre en update de escena para refrescar video */
	void update();

	/** regresa FBO del vídeo 
	@return devuelve fbo
	*/
	ofFbo fbo;

	/** se debe acceder para poder modificar sus propiedades
	@return devuelve el video tipo ofVideoPlayer */
	ofVideoPlayer video;
	


};



