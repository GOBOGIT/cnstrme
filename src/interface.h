#pragma once
#include "ofMain.h"

enum escena {inicio, principal, ayuda};
extern escena escenas;


class Interf {

	private:

		ofColor color;
		ofTrueTypeFont typo;
		
	public:

		ofColor cClick();
		ofColor cReleased();
		ofTrueTypeFont tipoBtn();
	
};


