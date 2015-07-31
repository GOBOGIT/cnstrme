#pragma once
#include "ofMain.h"
#include "../interface.h"

class boton {


public:

	void setup();
	void setup(escena, string);
	void draw(int,int,int);
	

	ofEvent <string> evento;
	

	void mouseMoved(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
	void mousePressed(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);

	int x, y, radio;
	
	bool dentro(float,float);
	bool esActivo;

	void desactivar();
	void activar();

	string texto;

	escena miescena;

};