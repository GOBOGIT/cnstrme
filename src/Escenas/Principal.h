#pragma once
#include "ofMain.h"
#include "../globales.h"

#include "ofxAssimpModelLoader.h"
#include "../Gui/Contenedor.h"
#include "../Gui//Boton.h"
#include "../Cajas/cajaTexto.h"
#include "../Cajas/cajaImagen.h"
#include "../Cajas/cajaGR_Circulos.h"
#include "../Cajas/cajaBoton.h"
#include "../3D/gestor3D.h"


class Principal {


public:

	Principal() {};
	~Principal() {};


	void draw(int _r, int _g, int _b);
	void update();

	void estados(bool);
	void activar();
	void desactivar();
	void iniciar(string);

	bool botonPanelActivo;

	gestor3D escena3D;
	ofLight iluminacion;

	boton botonPanel;
	boton btnContenedor;
	string titulo;

	Contenedor guiEstatico;
	
	cajaBoton cajaBtn;
	cajaTexto cajaTxt;
	cajaImagen cajaImg;
	cajaGrCirculos cajaCirculo, otraCajaC;
};