#include "interface.h"


ofColor interf::cReleased() {
	color.r = 255, color.g = 100, color.b = 10;
	cout << "cambio color" << endl;
	return color;
	}

ofColor interf::cClick() {
	color.r = 155, color.g = 200, color.b = 10;
	return color;
	}

