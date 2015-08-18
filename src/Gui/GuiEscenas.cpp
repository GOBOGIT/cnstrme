#include "GuiEscenas.h"

void GuiEscenas::setup() {

	//tween
	estado =true;
	delay = 20;
	duration = 300;
	POSY = 100;
	LARGO = 300;

	
	a = b = "inic";
	estados(0,0,0, a);

	//botones
	BtnInicio.setup("ESCENA 3D",0, "verde");
	BtnRegresaInicio.setup( "INICIO",0,"verde");
	BtnAyuda.setup("AYUDA",0,"verde");

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

void GuiEscenas::update() {

	BtnRegresaInicio.update(x,y);
	BtnInicio.update(x,y);
	BtnAyuda.update(x,y);
			
	if(a != b){
			if(a == "inc") estado = true;
			if((a=="pri") && (estado)) animacion();
			if(a =="ayu") estado = false;
	b = a;
	}

}

void GuiEscenas::animacion() {
	cout << "entraanim" << endl;
	animGuiLinear.setParameters(2,easinglinear,ofxTween::easeOut, 0,POSY,duration,delay);

}

void GuiEscenas::estados(bool _a, bool _b, bool _c, string _escena) {
	
	a = _escena;

	BtnRegresaInicio.estados(_a);
	BtnInicio.estados(_b);
	BtnAyuda.estados(_c);
}


