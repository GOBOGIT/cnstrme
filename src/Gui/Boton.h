#pragma once
#include "ofMain.h"
#include "ofxTween.h"
#include "../globales.h"



class boton {

private:

	Globales globales;
	bool estaDentro;
	bool isDrag;
	
	ofColor color;
	
	int posTextoX;
	int posTextoY;
	int Relx, Rely, radio;
	int Absx, Absy;
	int ancho, largo;
	bool eventos;
	
	float escala;
	ofTrueTypeFont typo;

	ofFbo fboImagen;
	ofFbo fboMascara;
	
	ofImage imagen;

public:

	enum tiposBotones{circuloTexto,circuloImagen,rectTexto,rectImagen};
	
	boton() {};
	boton(tiposBotones _tipoBtn, string _colorBoton);
	
	~boton() {};

	void update(int,int);
	
	void draw(ofVec2f,int,string);				// circulo: pos y radio
	void draw(ofVec2f,int,int,string);			//  rectángulo: pos, largo y ancho
	void draw(ofVec2f,int, ofImage);			// circulo: pos y radio con imagen
	void draw(ofVec2f,int,int,ofImage);			//  rectángulo: pos, largo , ancho e imagen



	ofEvent <string> evento;

	void mouseMoved(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
	void mousePressed(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);
	
	bool dentro(float,float);

	void estados(bool);

	bool getter() { return estaDentro; }
	void setter(bool _dentro){ estaDentro =_dentro;  };

	string colorBoton;
	string texto;
	
	//tiposBotones tipoBtn;
	tiposBotones tipoBoton;

};