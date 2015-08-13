#pragma once

#include "ofxTween.h"
#include "../globales.h"

class boton {

private:

	bool estaDentro;
	string texto;
	ofColor color;

	int tipoBoton;
	int posTextoX;
	int posTextoY;
	int Relx, Rely, radio;
	int Absx, Absy;
	int ancho, largo;

public:

	void setup(string, int);
	void update(int,int);
	void draw(int,int,int);		// circulo: pos y radio
	void draw(int,int,int,int); //  rectángulo: pos, largo y ancho

	ofEvent <string> evento;

	void mouseMoved(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
	void mousePressed(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);
	
	bool dentro(float,float);

	void estados(bool);
	bool getter();
	void setter(bool);

	ofTrueTypeFont typo;

};