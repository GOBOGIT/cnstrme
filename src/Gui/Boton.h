#pragma once
#include "ofMain.h"
#include "ofxTween.h"
#include "../globales.h"


class boton {

private:

	Globales globales;
	bool estaDentro;
	string texto;
	ofColor color;
	int tipoBoton;
	int posTextoX;
	int posTextoY;
	int Relx, Rely, radio;
	int Absx, Absy;
	int ancho, largo;
	
	float escala;
	ofTrueTypeFont typo;

	ofFbo fboImagen;
	ofFbo fboMascara;

	ofImage imagen;
public:

	boton() {};
	boton(string _texto, int _tipoBoton, string _colorBoton);
	
	~boton() { cout << "dBoton" ;};

	void setup(string, int, string);
	void update(int,int);
	void draw(int,int,int);				// circulo: pos y radio
	void draw(int,int,int,int);			//  rectángulo: pos, largo y ancho

	void draw(int,int,int, ofImage);	// circulo: pos y radio con imagen

	ofEvent <string> evento;

	void mouseMoved(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
	void mousePressed(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);
	
	bool dentro(float,float);

	void estados(bool);

	bool getter() { return estaDentro; }
	void setter(bool _dentro){ estaDentro =_dentro;  }

	string colorBoton;

};