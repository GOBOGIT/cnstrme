#pragma once

#include "ofMain.h"
#include "../Globales.h"
#include "../Gui/Boton.h"
#include "../Gui/Contenedor.h"
#include "../Cajas/cajaImagen.h"
#include "../Cajas//cajaTexto.h"
#include "../Gui/Grid.h"

class Galeria {

	
public:

	Galeria() {};
	~Galeria() {};


	void draw(int _r, int _g, int _b);
	void update();


	void iniciar(string);
	void estados(bool);

	// matriz para carga de muestra
	vector<Contenedor> matrizContenedores;
	vector<Contenedor> muchosC;
	ofVideoPlayer prueba;
	ofFbo fboPrueba;

	string titulo;
	cajaImagen cajaImg;
	cajaTexto cajaTxt;

	boton botones;
	Contenedor contenedor;
	Grid grid;
	
};