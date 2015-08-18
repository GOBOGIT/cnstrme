#pragma once
#include "ofMain.h"


class Globales {

	private:

		static ofColor color;


		
	public:

		static ofColor bgGris();

		static ofTrueTypeFont typo;
		static ofTrueTypeFont typoTitulo;
		static ofTexture imagenEstaticos;
		static ofVideoPlayer videoAnim;

		static map<string, map<string, ofColor>> paqueteColores;

		static void assets();
	
};


