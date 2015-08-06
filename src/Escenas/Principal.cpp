#include "Principal.h"


void Principal::iniciar() {


	// setup de la camara
	cam.setPosition(ofPoint(ofGetWidth()/2, ofGetHeight()/2, 700));

	// carga el modelo de ejemplo
	// importar desde Blender con eje -Z
	modelo.loadModel("modelo.3ds", true);

	//carga guiEstatico
	guiEstatico.setup();

}


void Principal::draw(int _r, int _g, int _b) {
	ofBackground(_r, _g, _b);

	cam.begin();
		ofPushMatrix();
			//http://www.openframeworks.cc/documentation/ofxAssimpModelLoader/ofxAssimpModelLoader.html
			modelo.draw(OF_MESH_WIREFRAME);
		ofPopMatrix();
	cam.end();

	guiEstatico.draw(ofGetWindowWidth()/2,ofGetWindowHeight()/2, 200,400);

}


void Principal::estados(bool _estado){

	if(_estado) {
		cam.enableMouseInput();
	} else {
		cam.disableMouseInput();
	}
}





