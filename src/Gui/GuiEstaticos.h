#pragma once;

#include "ofMain.h"

class GuiEstaticos {


public:


	void setup();
	void draw(int,int, int, int);
	void update();
	void estados(bool);

	int posx;
	int posy;

	int largo;
	int ancho;

};