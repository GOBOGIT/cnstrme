#pragma once
#include "ofMain.h"
#include "../Escena.h"

class Principal: public Escena {

	bool botonPanelActivo;
	boton botonPanel;
	boton btnContenedor;
	
	gestor3D escena3D;
	Contenedor guiEstatico;
	
	cajaBoton cajaBtn;
	cajaTexto cajaTxt;
	cajaImagen cajaImg;
	cajaGrCirculos cajaCirculo, otraCajaC;

public:

	Principal() {};
	~Principal() {};

	void draw(int _r, int _g, int _b);
	void setup();
	void update();
	void estados(bool);
};