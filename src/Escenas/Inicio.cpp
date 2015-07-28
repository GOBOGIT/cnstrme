
#include "Inicio.h"



void Inicio::ImagenInicio() {

	ofLoadImage(imagen, "imagenInicio.png");

}


void Inicio::draw(int _r, int _g, int _b) {

	ofBackground(_r, _g, _b);
	imagen.draw((ofGetWidth()/2 )- imagen.getWidth()/2, (ofGetHeight()/2) - imagen.getHeight()/2);

}