
#include "Inicio.h"
#include "../ofApp.h"



void Inicio::iniciar() {

	//tween
	delay = 500;
	duration = 1500;
	// carga fuente
	typo.loadFont("OCRAStd.otf", 10, true, false, true);
	typo.setLineHeight(18.0f);
	typo.setLetterSpacing(1.02);
	// imagen
	animImagenInicio.setParameters(7,easingelastic,ofxTween::easeOut, 70,100,duration,delay);
	ofLoadImage(imagen, "imagenInicio.png");
	// boton
	BtnInicio.setup(principal, "INICIAR",typo);

}


void Inicio::draw(int _r, int _g, int _b) {
	ofBackground(_r, _g, _b);
	imagen.draw((ofGetWidth()/2 )- imagen.getWidth()/2, ((ofGetHeight()/2) - imagen.getHeight()/2)-animImagenInicio.update());
	BtnInicio.draw((ofGetWidth()/2 ), (ofGetHeight()/2) +  150,50);


}


void Inicio::estados(bool _estado) {

	if(_estado){
		delay = 0;
		animImagenInicio.setParameters(7,easingelastic,ofxTween::easeOut, 70,+100,duration,delay);
	}

}
