#pragma once

#include "ofMain.h"
#include "BtnCirculo.h"
#include "../globales.h"

class GuiEstaticos {


private:

	float posx;
	float posy;
	vector<unsigned int> posyFila;


	int largo;
	int anchoFinal;
	int barra;
	bool estaDentro;
	bool iniciaAnim;
	bool btnSalida;


public:

	/** inicializa el contenedor
		@param posicion x e y absolutos
		@param titulo de la ventana
		@param crear boton de salida? */
	void setup(int, int, string, bool);
	void draw(int,int);
	void update();
	void estados(bool);
	void animacion();

	ofEvent <string> evento;
	void mouseMoved(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
	void mousePressed(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);

	bool dentro(float,float);
	void fila(ofFbo);
	vector<ofFbo> filas;

	bool getter();
	void setter(bool);


	boton botonSalir;
	ofTrueTypeFont titulo;
	string textoTitulo;

	ofxTween animacionContenedor;
	ofxEasingLinear easinglinear;
};