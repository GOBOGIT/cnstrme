#include "Ayuda.h"

extern Globales globales;

void Ayuda::iniciar() {
	

	// inicializa botón de inicio !! las coordenadas de posición deben ir en la función draw
	// para que a la hora de ajustar la ventana se coloque correctamente
	cajaVideo = cajaAnim(400,300, globales.videoAnim);
	cajaTxt = cajaTexto(400,100, "haz click y arrastra el mouse en la escena 3D para poder\nnavegar por ella");
	
	contenedorVideo.fila(cajaVideo.fbo);
	contenedorVideo.fila(cajaTxt.fbo);
	contenedorVideo.setup(400,400, "VIDEO", false);

}


void Ayuda::draw(int _r, int _g, int _b) {

	ofBackgroundGradient(ofColor::white,globales.bgGris(), OF_GRADIENT_CIRCULAR);
	contenedorVideo.draw(ofGetWidth() - 450,50);

}


void Ayuda::update() {
	
	if(estado) {
		cajaVideo.video.play();
		cajaVideo.update();
	} else {
		cajaVideo.video.setPosition(0);
		cajaVideo.video.stop();
	}

}

void Ayuda::estados(bool _estado) {

	if(_estado) {
		estado = true;
	} else {
		estado = false;
	}

}



