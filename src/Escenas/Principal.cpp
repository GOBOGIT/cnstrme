#include "Principal.h"


// desde extern ofapp
extern Globales globales;

void Principal::iniciar() {


	// setup de la camara
	cam.setPosition(ofPoint(ofGetWidth()/2, ofGetHeight()/2, 700));

	// carga el modelo de ejemplo
	// importar desde Blender con eje -Z
	modelo.loadModel("modelo.3ds", true);

	botonPanel.setup("Panel",0);
	botonPanelActivo = true;


	// setup del contenedor
	guiEstatico.setup(400,400, "ESTATICO");
	// inicializa cajas
	cajaTxt = cajaTexto(400,100, "Porcentaje de llamadas totales\n por números de clicks");
	cajaImg = cajaImagen(400,400, globales.imagenEstaticos);
	// envia cajas a contenedor
	guiEstatico.cajaTexto(cajaTxt.FboCajaTexto);
	guiEstatico.cajaImagen(cajaImg.FboCajaImagen);

	
}


void Principal::draw(int _r, int _g, int _b) {
	ofBackground(_r, _g, _b);

	cam.begin();
		ofPushMatrix();
			//http://www.openframeworks.cc/documentation/ofxAssimpModelLoader/ofxAssimpModelLoader.html
			modelo.draw(OF_MESH_WIREFRAME);
		ofPopMatrix();
	cam.end();

	botonPanel.update(100,ofGetWindowHeight() -200);
	botonPanel.draw(0,0, 50);

	if(!botonPanelActivo)
		guiEstatico.draw(ofGetWidth() - 450,50);

	update();
}


void Principal::update(){

	if(botonPanelActivo){
		if(botonPanel.getter()) {
			botonPanelActivo = false;
			botonPanel.setter(false);
		}
		botonPanel.estados(true);
	} else {
		botonPanel.estados(false);
		if(guiEstatico.botonSalir.getter()){
			guiEstatico.botonSalir.setter(false);
			botonPanelActivo = true;
		}
	}

	// revisar, problemas con el mouse
	if(guiEstatico.getter()) {
		cout << "entra disable" << endl;
		cam.disableMouseInput();
	}
	else
		cam.enableMouseInput(); 

}

void Principal::activar() {
	botonPanel.estados(true);
	cam.enableMouseInput(); 

}
void Principal::desactivar() {
	botonPanel.estados(false);
	cam.disableMouseInput();

}






