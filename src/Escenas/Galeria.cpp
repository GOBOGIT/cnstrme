#include "Galeria.h"

extern Globales globales;

void Galeria::iniciar(string _titulo) {

	titulo = _titulo;
	// contenedor a repetir
	cajaImg = cajaImagen(260,160,globales.mockupImagen160x160, 0);
	cajaTxt = cajaTexto(260,50, "Imagen", ofColor::lightGray, ofColor::black, 1);
	cajaGrCirculos cajaC = cajaGrCirculos(0,260,210,200,350);

	Contenedor muchosCont[18];
	muchosC.resize(18);

		
		muchosCont[0].fila(cajaC);
		muchosCont[0].setup(260,210, "", false, false);
		muchosC[0] = muchosCont[0];
		grid.estados(true);
		for(unsigned int i = 1; i < 18; i++) {
			muchosCont[i].fila(cajaImg);
			muchosCont[i].fila(cajaTxt);
			muchosCont[i].setup(260,210, "", false, false);
			muchosC[i] = muchosCont[i];
	} 
		grid.add(muchosC);
}


void Galeria::draw(int _r, int _g, int _b) {


	ofBackgroundGradient(ofColor::white,globales.bgGris(), OF_GRADIENT_CIRCULAR);
	ofPushMatrix();
		//ofTranslate((ofGetWindowWidth()/2) -(1200)/2, 0);
			grid.draw(0,100,ofGetWindowWidth(), ofGetWindowHeight()-300);
	ofPopMatrix();

}


void Galeria::update() {

}

void Galeria::estados(bool _estado) {}



