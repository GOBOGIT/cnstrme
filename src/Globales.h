#pragma once
#include "ofMain.h"


class Globales {

	private:

		static ofColor color;
		
	public:

		static ofColor cClick();
		static ofColor cReleased();
		static ofColor cDisable();
		static ofColor bgGris();


		static ofTrueTypeFont typo;
		static 	ofTexture imagenEstaticos;
	
		static void assets();
	
};


