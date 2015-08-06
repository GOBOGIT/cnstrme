#include "GuiEscenas.h"

void GuiEscenas::setup() {

	//tween
	estado =true;
	delay = 20;
	duration = 300;
	POSY = 100;
	LARGO = 300;

	escenaSel = inicio;
	// en caso de que pantalla inicial se "INICIO"
	estados(0,0,0);
	// ejecuta la animación por primera vez
	animacion();

	// carga fuente
	typo.loadFont("OCRAStd.otf", 10, true, false, true);
	typo.setLineHeight(18.0f);
	typo.setLetterSpacing(1.02);

	//botones
	BtnInicio.setup(principal, "ESCENA 3D",typo);
	BtnRegresaInicio.setup(inicio, "INICIO",typo);
	BtnAyuda.setup(ayuda,"AYUDA",typo);

}

void GuiEscenas::draw(float _x, float _y) {

	// posicion de la caja
	x = _x - LARGO / 2;
	if(!estado) 
		y = _y - POSY;
	else {
		y = _y - animGuiLinear.update();
		if(	animGuiLinear.isCompleted())	estado = false;
	}

	ofPushMatrix();
			BtnRegresaInicio.draw(0,0,50);
			BtnInicio.draw(150,0,50);
			BtnAyuda.draw(300,0,50);
	ofPopMatrix();

}

void GuiEscenas::update(escena _escena) {


	// necesario para actualizar coordenadas del listener
	BtnRegresaInicio.update(x,y);
	BtnInicio.update(x,y);
	BtnAyuda.update(x,y);
	
	if(escenaSel !=escenas) {
		switch(_escena) {
			case inicio: 
				estados(0,0,0);
				estado = true;
				break;
			case principal:
				estados(1,0,1);
				if(estado) animacion();
				break;
			case ayuda: 
				estados(1,1,0);
				estado = false;
				break;
		}
	escenaSel = escenas;
	}
}

void GuiEscenas::animacion() {
	animGuiLinear.setParameters(2,easinglinear,ofxTween::easeOut, 0,POSY,duration,delay);

}

void GuiEscenas::estados(bool _a, bool _b, bool _c) {
	BtnRegresaInicio.estados(_a);
	BtnInicio.estados(_b);
	BtnAyuda.estados(_c);
}



