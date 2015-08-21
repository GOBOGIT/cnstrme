#pragma once

#include "ofMain.h"
#include "Boton.h"
#include "../globales.h"

class Contenedor {


private:

	float posx;
	float posy;
	vector<unsigned int> posyFila;



	int barra;
	bool estaDentro;
	bool iniciaAnim;
	bool btnSalida;
	bool b_barra;


public:



	/** inicializa el contenedor
		@param posicion x e y absolutos
		@param titulo de la ventana
		@param crear boton de salida? 
		@param activar barra?	*/
	void setup(int, int, string, bool, bool);
	void draw(int,int);
	void update();
	void estados(bool);
	void animacion();
	
	/** añade elementos al contenedor */
	void fila(ofFbo);

	ofEvent <string> evento;
	void mouseMoved(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
	void mousePressed(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);

	vector<ofFbo> filas;

	int largo;
	int anchoFinal;

	bool dentro(float,float);
	bool getter();
	void setter(bool);


	boton botonSalir;
	ofTrueTypeFont titulo;
	string textoTitulo;

	ofxTween animacionContenedor;
	ofxEasingLinear easinglinear;
};