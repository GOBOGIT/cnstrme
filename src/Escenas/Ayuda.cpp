#include "Ayuda.h"


void Ayuda::iniciar() {
	
	// carga fuente
	typo.loadFont("OCRAStd.otf", 10, true, false, true);
	typo.setLineHeight(18.0f);
	typo.setLetterSpacing(1.02);
	// inicializa bot�n de inicio !! las coordenadas de posici�n deben ir en la funci�n draw
	// para que a la hora de ajustar la ventana se coloque correctamente
	
	BtnRegresaPrincipal.setup(principal, "REGRESAR", typo);

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


