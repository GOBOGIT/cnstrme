#pragma once
#include "ofMain.h"

class cajaAnim{


	int ancho, largo;

public:

	cajaAnim() {};
	cajaAnim(int,int, ofVideoPlayer);

	void draw();
	void update();

	string texto;
	ofFbo fbo;
	ofVideoPlayer video;


};



