#include "Loop.h"

void Loop::setup() {
	//tween
	delay = 500;
	duration = 1500;
	// imagen logo
	animImagenInicio.setParameters(7,easingelastic,ofxTween::easeOut, 70,100,duration,delay);
	imagen = Globales::imagenes["logo"];
	// boton
	estado= false;
	BtnInicio.setup(boton::circuloImagen, "verde");
	//video HAP
	videoF = Globales::videoHap["videoLoop"];
	videoF->setLoopState(OF_LOOP_NORMAL);
}

void Loop::draw(int _r, int _g, int _b) {
	ofBackgroundGradient(ofColor::white,Globales::color["gris220"], OF_GRADIENT_CIRCULAR);
	 
	if (videoF->isLoaded()) {
			videoF->draw(0,0, ofGetWindowWidth(), ofGetWindowHeight());
			videoF->update();
	 } 

	imagen.draw((ofGetWidth()/2 )- imagen.getWidth()/2, ((ofGetHeight()/2) - imagen.getHeight()/2)-animImagenInicio.update());
	BtnInicio.draw(ofVec2f(ofGetWidth()/2 , (ofGetHeight()/2) +  150),128, Globales::iconos["iconoInicio"]);

	if (BtnInicio.getter()){
			BtnInicio.setter(false);
			estado= true;
		} 
}

void Loop::estados(bool _estado) {
	if(_estado){
		delay = 0;
		animImagenInicio.setParameters(7,easingelastic,ofxTween::easeOut, 70,+100,duration,delay);
		BtnInicio.estados(true);
		if (videoF->isLoaded()) 
			videoF->play();
	} else {
	BtnInicio.estados(false);
		videoF->stop();
		videoF->setPosition(0);
	}
}

