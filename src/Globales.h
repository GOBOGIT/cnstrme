#pragma once
#include "ofMain.h"

class Globales {
		
	public:

		static ofColor bgGris();
		static ofColor bgGrisOscuro();

		static map<string,ofImage> iconos;
		static map<string,ofImage> imagenes;
		static map<string,ofTrueTypeFont> tipografia;

		static ofVideoPlayer videoAnim;

		static map<string, map<string, ofColor>> paqueteColores;
		static map<string, ofColor> color;

		static void assets();
	
};


