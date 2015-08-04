#include "Principal.h"


void Principal::iniciar() {


	// carga fuente
	typo.loadFont("OCRAStd.otf", 10, true, false, true);
	typo.setLineHeight(18.0f);
	typo.setLetterSpacing(1.02);
	// setup de la camara
	cam.setPosition(ofPoint(ofGetWidth()/2, ofGetHeight()/2, 700));

	// carga el modelo de ejemplo
	// importar desde Blender con eje -Z
	modelo.loadModel("modelo.3ds", true);


	//inicializa los botones
	BtnRegresaInicio.setup(inicio, "INICIO",typo);
	BtnAyuda.setup(ayuda,"AYUDA",typo);
}


void Principal::draw(int _r, int _g, int _b) {
	ofBackground(_r, _g, _b);

	cam.begin();
		ofPushMatrix();
			//http://www.openframeworks.cc/documentation/ofxAssimpModelLoader/ofxAssimpModelLoader.html
			modelo.draw(OF_MESH_WIREFRAME);
		ofPopMatrix();
	cam.end();
    
	BtnRegresaInicio.draw(100,ofGetHeight() - 100,50);
	BtnAyuda.draw( ofGetWidth() -100,ofGetHeight() - 100,50);

}



void Principal::desactivar() {
	BtnRegresaInicio.desactivar();
	BtnAyuda.desactivar();
	cam.disableMouseInput();
}

void Principal::activar() {
	BtnRegresaInicio.activar();
	BtnAyuda.activar();
	cam.enableMouseInput();
}




