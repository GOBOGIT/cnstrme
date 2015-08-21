#include "Galeria.h"

extern Globales globales;

void Galeria::iniciar() {

	// contenedor a repetir
	cajaImg = cajaImagen(260,160,globales.mockupImagen160x160);
	cajaTxt = cajaTexto(260,50, "Imagen", ofColor::lightGray, ofColor::black);

	Contenedor muchosCont[18];
	vector<Contenedor> muchosC;
	muchosC.resize(18);

		for(unsigned int i = 0; i < 18; i++) {
		
		muchosCont[i].fila(cajaImg.FboCajaImagen);
		muchosCont[i].fila(cajaTxt.fbo);
		muchosCont[i].setup(260,210, "", false, false);
		muchosC[i] = muchosCont[i];
	} 
		grid.add(muchosC);
}


void Galeria::draw(int _r, int _g, int _b) {

	ofBackgroundGradient(ofColor::white,globales.bgGris(), OF_GRADIENT_CIRCULAR);
	ofPushMatrix();
		//ofTranslate((ofGetWindowWidth()/2) -(1200)/2, 0);
			grid.draw(0,100,ofGetWindowWidth(), 600);
	ofPopMatrix();

}


void Galeria::update() {}

void Galeria::estados(bool _estado) {}



