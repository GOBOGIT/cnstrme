#include "globales.h"

ofTrueTypeFont Globales::typo = ofTrueTypeFont();
ofTexture Globales::imagenEstaticos = ofTexture();
ofColor Globales::color = ofColor();

ofColor Globales::cReleased() {
color.r = 195, color.g = 225, color.b = 195;
	return color;
	}

ofColor Globales::cClick() {
	color.r = 150, color.g = 225, color.b = 150;
	return color;
	}

ofColor Globales::cDisable() {
	color.r = 200, color.g = 200, color.b = 200;
	return color;
	}

ofColor Globales::bgGris() {
	color.r = 250, color.g = 250, color.b = 250;
	return color;
	}


void Globales::assets() {
		typo.loadFont("OCRAStd.otf", 10, true, false, true, 0.1); 
		ofLoadImage(imagenEstaticos, "circuloEstatico.png");
}