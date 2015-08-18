#include "Inicio.h"

// desde extern ofapp
extern Globales globales;

void Inicio::iniciar() {

	//tween
	delay = 500;
	duration = 1500;
	// carga fuente

	// imagen
	animImagenInicio.setParameters(7,easingelastic,ofxTween::easeOut, 70,100,duration,delay);
	ofLoadImage(imagen, "imagenInicio.png");
	// boton
	click = false;
	BtnInicio.setup("INICIAR", 0, "verde");

}

void Inicio::draw(int _r, int _g, int _b) {
 
	ofBackgroundGradient(ofColor::white,globales.bgGris(), OF_GRADIENT_CIRCULAR);
	
	//ofBackground(_r, _g, _b);
	imagen.draw((ofGetWidth()/2 )- imagen.getWidth()/2, ((ofGetHeight()/2) - imagen.getHeight()/2)-animImagenInicio.update());
	BtnInicio.draw((ofGetWidth()/2 ), (ofGetHeight()/2) +  150,50);

	if (BtnInicio.getter()){
			BtnInicio.setter(false);
			click= true;
		}

}


void Inicio::estados(bool _estado) {

	if(_estado){
		delay = 0;
		animImagenInicio.setParameters(7,easingelastic,ofxTween::easeOut, 70,+100,duration,delay);
	}

}

bool Inicio::getter(){
	return click;
}

void Inicio::setter(bool _click){
	click = false;
}
