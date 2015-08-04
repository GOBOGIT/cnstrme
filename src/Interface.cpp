#include "interface.h"


ofColor Interf::cReleased() {
	color.r = 195, color.g = 225, color.b = 195;
	return color;
	}

ofColor Interf::cClick() {
	color.r = 150, color.g = 225, color.b = 150;
	return color;
	}

ofTrueTypeFont Interf::tipoBtn() {
	
	typo.loadFont("OCRAStd.otf", 10, true, false, true);
	typo.setLineHeight(18.0f);
	typo.setLetterSpacing(1.02);
	return typo;

}


