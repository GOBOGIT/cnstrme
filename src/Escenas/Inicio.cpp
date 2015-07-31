
#include "Inicio.h"
#include "../ofApp.h"
//#include "../interface.h"


void Inicio::iniciar() {
	ofLoadImage(imagen, "imagenInicio.png");
	BtnInicio.setup(principal, "desde inicio");
}


void Inicio::draw(int _r, int _g, int _b) {
	ofBackground(_r, _g, _b);
	imagen.draw((ofGetWidth()/2 )- imagen.getWidth()/2, ((ofGetHeight()/2) - imagen.getHeight()/2)-100);
	BtnInicio.draw((ofGetWidth()/2 ), (ofGetHeight()/2) +  150,50);
}


void Inicio::desactivar(){
	BtnInicio.desactivar();
}

void Inicio::activar(){
	BtnInicio.activar();
}
