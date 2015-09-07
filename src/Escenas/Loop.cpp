#include "Loop.h"

void Loop::iniciar(string _titulo) {
	
	titulo = _titulo;
	//tween
	delay = 500;
	duration = 1500;
	// carga fuente

	// imagen
	animImagenInicio.setParameters(7,easingelastic,ofxTween::easeOut, 70,100,duration,delay);
	ofLoadImage(imagen, "imagenInicio.png");
	
	// boton
	click = false;
	//boton BtnInicio(boton::circuloImagen,"verde");
	BtnInicio = boton(boton::circuloImagen,"verde");
	//BtnInicio.setup("INICIAR",0,"verde");

}

void Loop::draw(int _r, int _g, int _b) {
 
	ofBackgroundGradient(ofColor::white,Globales::color["gris220"], OF_GRADIENT_CIRCULAR);
	
	//ofBackground(_r, _g, _b);
	imagen.draw((ofGetWidth()/2 )- imagen.getWidth()/2, ((ofGetHeight()/2) - imagen.getHeight()/2)-animImagenInicio.update());
	BtnInicio.draw(ofVec2f(ofGetWidth()/2 , (ofGetHeight()/2) +  150),128, Globales::iconos["iconoInicio"]);

	if (BtnInicio.getter()){
			BtnInicio.setter(false);
			click= true;
		}

}

void Loop::estados(bool _estado) {

	if(_estado){
		delay = 0;
		animImagenInicio.setParameters(7,easingelastic,ofxTween::easeOut, 70,+100,duration,delay);
		BtnInicio.estados(true);
	} else {

	BtnInicio.estados(false);
	}

}

bool Loop::getter(){
	return click;
}

void Loop::setter(bool _click){
	click = false;
}
