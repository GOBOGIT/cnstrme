#pragma once

#include "ofMain.h"
#include "Boton.h"
#include "../globales.h"
#include "../Cajas/cajaGR_Circulos.h"
#include "../Cajas/cajaTexto.h"
#include "../Cajas/cajaImagen.h"
#include "../Cajas/cajaBoton.h"

class Contenedor {


private:

	float posx;
	float posy;
	vector<unsigned int> posyFila;
	vector<unsigned int>anchoCaja;

	vector<cajaTexto> cajasTexto;
	vector<cajaGrCirculos> cajasCirculos;
	vector<cajaImagen> cajasImagen;


	int barra;
	bool estaDentro;
	bool iniciaAnim;
	bool btnSalida;
	bool b_barra;
	bool eventos;

public:

	Contenedor() {}
	~Contenedor() {}

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

	map<string, cajaBoton> cajasBotones;
	
	/** añade elementos al contenedor */
	void fila(cajaGrCirculos);
	void fila(cajaTexto);
	void fila(cajaImagen);
	void fila(cajaBoton);


	//ofEvent <string> evento;
	void mouseMoved(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
	void mousePressed(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);

	vector<ofFbo> filas;

	int largo;
	int anchoFinal;

	bool dentro(float,float);
	bool getter(){return estaDentro;};
	void setter(bool);


	boton botonSalir;
	ofTrueTypeFont titulo;
	string textoTitulo;

	ofxTween animacionContenedor;
	ofxEasingLinear easinglinear;



};