#pragma once

#include "ofMain.h"
#include "../Escena.h"

class Galeria: public Escena {
	
	bool esRafaga;
	Contenedor muchosCont[18];
	map<int,Contenedor> muchosC;

public:

	Galeria() {};
	~Galeria() {};

	void draw(int _r, int _g, int _b);
	void setup();
	void estados(bool);
	
	boton btn;
	Grid grid;
	
};