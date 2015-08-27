#pragma once
#include "ofMain.h"

class Globales {

	private:

		static ofColor color;


		
	public:

		static ofColor bgGris();
		static ofColor bgGrisOscuro();

		static ofTrueTypeFont typo;
		static ofTrueTypeFont typoTitulo;
		static ofTexture imagenEstaticos;
		static ofTexture mockupImagen160x160;
		static ofTexture mockupImagen1000x500;
		static ofImage	imagenUV;
		static ofVideoPlayer videoAnim;

		static map<string, map<string, ofColor>> paqueteColores;

		static void assets();
	
};


