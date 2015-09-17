#include "Galeria.h"


void Galeria::setup() {

	int const NUM_ELEMENTOS = 18;
	
	boton *btn[NUM_ELEMENTOS];

	cajaBoton cajaBtn;
	cajaTexto *cajaTxt[NUM_ELEMENTOS];
	cajaGrCirculos cajaC = cajaGrCirculos(0,260,210,200,350);

		muchosCont[0].fila(cajaC);
		muchosCont[0].setup(260,210, "", false, false);
		muchosC.emplace(0,move(muchosCont[0]));

		for(unsigned int i = 1; i < NUM_ELEMENTOS; i++) {

			btn[i] = new boton();
			btn[i]->setup(boton::rectTexto,"verde");
			cajaBtn = cajaBoton(0,260,160, "hola", *btn[i]);
			
			cajaTxt[i] = new cajaTexto(1,260,50, ofToString(rand()), ofColor::lightGray, ofColor::black);
			
			muchosCont[i].fila(cajaBtn);
			muchosCont[i].fila(*cajaTxt[i]);
			muchosCont[i].setup(260,210, "", false, false);
			muchosC.emplace(i,move(muchosCont[i]));
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

void Galeria::estados(bool _estado) {
	grid.estados(_estado);
}



