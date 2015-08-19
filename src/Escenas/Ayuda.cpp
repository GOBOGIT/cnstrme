#include "Ayuda.h"


void Ayuda::iniciar() {

	// inicializa bot�n de inicio !! las coordenadas de posici�n deben ir en la funci�n draw
	// para que a la hora de ajustar la ventana se coloque correctamente
	BtnRegresaPrincipal.setup(principal, "desde ayuda");


}


void Ayuda::draw(int _r, int _g, int _b) {

	ofBackground(_r, _g, _b);
	BtnRegresaPrincipal.draw(100,ofGetHeight() - 100,50);

}


void Ayuda::desactivar() {
	BtnRegresaPrincipal.desactivar();
}

void Ayuda::activar() {
	BtnRegresaPrincipal.activar();
}


