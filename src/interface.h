#pragma once
#include "ofMain.h"

enum escena {inicio, principal, ayuda};
extern escena escenas;

	
class interf {

	private:

		ofColor color;

	public:

		ofColor cClick();
		ofColor cReleased();
};


