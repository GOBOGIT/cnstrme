#include "Galeria.h"



void Galeria::iniciar(string _titulo) {

	titulo = _titulo;
	// contenedor a repetir
	//cajaImg = cajaImagen(260,160,Globales::imagenes["mockup160x160"], 0);
	
	
	btn = boton(boton::rectTexto,"verde");
	cajaBtn = cajaBoton(0,260,160, "hola", btn);
	cajaTxt = cajaTexto(1,260,50, "Imagen", ofColor::lightGray, ofColor::black);
	cajaGrCirculos cajaC = cajaGrCirculos(0,260,210,200,350);

	Contenedor muchosCont[18];
	muchosC.resize(18);

		muchosCont[0].fila(cajaC);
		muchosCont[0].setup(260,210, "", false, false);
		muchosC[0] = muchosCont[0];
		
		
		for(unsigned int i = 1; i < 18; i++) {
			muchosCont[i].fila(cajaBtn);
			muchosCont[i].fila(cajaTxt);
			muchosCont[i].setup(260,210, "", false, false);
			muchosC[i] = muchosCont[i];
	} 
		grid.add(muchosC);
		
		grid.setup();
	
}


void Galeria::draw(int _r, int _g, int _b) {
	
	ofBackgroundGradient(ofColor::white,Globales::color["gris220"], OF_GRADIENT_CIRCULAR);
	ofPushMatrix();
			grid.draw(0,150,ofGetWindowWidth(), ofGetWindowHeight()-200);
	ofPopMatrix();

}


void Galeria::update() {}

void Galeria::estados(bool _estado) {
	grid.estados(_estado);

}



