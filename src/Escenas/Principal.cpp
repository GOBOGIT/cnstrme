#include "Principal.h"


void Principal::iniciar() {
	// inicializa botón de inicio !! las coordenadas de posición deben ir en la función draw
	// para que a la hora de ajustar la ventana se coloque correctamente
	BtnRegresaInicio.setup(inicio, "desde principal");
	BtnAyuda.setup(ayuda,"desde principal");
}


void Principal::draw(int _r, int _g, int _b) {
	ofBackground(_r, _g, _b);
	BtnRegresaInicio.draw(100,ofGetHeight() - 100,50);
	BtnAyuda.draw( ofGetWidth() -100,ofGetHeight() - 100,50);

}


void Principal::desactivar() {
	BtnRegresaInicio.desactivar();
	BtnAyuda.desactivar();
}

void Principal::activar() {
	BtnRegresaInicio.activar();
	BtnAyuda.activar();
}




