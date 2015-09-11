#pragma once
#include "ofMain.h"
#include "ofxTween.h"
#include "../globales.h"



class boton {

private:

	
	bool estaDentro;
//	bool isDrag;
	bool eventos;
	
	Globales globales;
	ofColor color;
	ofTrueTypeFont typo;
	ofImage imagen;
	
	int posTextoX;
	int posTextoY;
	int  radio;
	int ancho, largo;
	float escala;
	
	ofMatrix4x4 posicion;
	ofPoint origen;
	

public:

	enum tiposBotones{circuloTexto,circuloImagen,rectTexto,rectImagen};
	
	boton() {};
	boton(tiposBotones _tipoBtn, string _colorBoton){
		posicion(0,0);
		tipoBoton = _tipoBtn;
		escala = 1;
		colorBoton = _colorBoton;
		eventos =false;
		estaDentro = false;

		typo = Globales::tipografia["med"];
		typo.setLineHeight(18.0f); 
 		typo.setLetterSpacing(1.02); 

		color = Globales::paqueteColores[colorBoton]["normal"];
	};
	
	~boton() {};

	void update(int,int);
	
	void draw(ofVec2f,int,string);				// circulo: pos y radio
	void draw(ofVec2f,int,int,string);			//  rectángulo: pos, largo y ancho
	void draw(ofVec2f,int, ofImage);			// circulo: pos y radio con imagen
	void draw(ofVec2f,int,int,ofImage);			//  rectángulo: pos, largo , ancho e imagen

	//ofEvent <string> evento;

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
	
	tiposBotones tipoBoton;

};