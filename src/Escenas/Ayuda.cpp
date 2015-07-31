#include "Ayuda.h"


void Ayuda::iniciar() {

	// inicializa botón de inicio !! las coordenadas de posición deben ir en la función draw
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


