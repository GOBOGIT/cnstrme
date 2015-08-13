#pragma once

#include "ofMain.h"
#include "BtnCirculo.h"
#include "../globales.h"

class GuiEstaticos {


public:


	void setup(int, int, string);
	void draw(int,int);
	void update();
	void estados(bool);

	ofEvent <string> evento;
	void mouseMoved(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
	void mousePressed(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);

	bool dentro(float,float);
	void cajaTexto(ofFbo);
	void cajaImagen(ofFbo);

	bool getter();
	void setter(bool);

	float posx;
	float posy;

	int largo;
	//int ancho;
	int anchoFinal;
	int barra;

	float anchoCajaTexto, anchoCajaImagen;

	bool estaDentro;

	boton botonSalir;
	ofFbo FboTexto, FboImagen;
	ofTrueTypeFont titulo;
	string textoTitulo;
};