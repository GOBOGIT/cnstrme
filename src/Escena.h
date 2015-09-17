#pragma once
#include "Globales.h"
// cajas
#include "Cajas/cajaImagen.h"
#include "Cajas/cajaTexto.h"
#include "Cajas/cajaBoton.h"
#include "Cajas/cajaGR_Circulos.h"
// contenedores
#include "Gui/Boton.h"
#include "Gui/Grid.h"
#include "Gui/Contenedor.h"
// addons
#include "ofxHapPlayer.h"
#include "ofxAssimpModelLoader.h"
//gestores
#include "3D/gestor3D.h"

class Escena {

protected:

	Escena(){};
	~Escena(){};

	bool estado;

	void virtual draw(int,int,int){};
	
	// define el estado de la escena: activo o desactivado
	void virtual estados(bool _estado){};
	
	// sirve para activar elementos dentro de la escena, idnependientemente de si está o no activado
	void virtual setter(bool _setter) {estado = _setter;}
	// devluelve el estado de setter
	bool virtual getter(){return estado;};


public:

	void virtual update() {};
	string titulo;
};

