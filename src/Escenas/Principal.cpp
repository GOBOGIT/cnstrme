#include "Principal.h"
#include "../3D/3DLoader.h"


// desde extern ofapp
extern Globales globales;

void Principal::iniciar() {

	// setup de la camara
	cam.setPosition(ofPoint(ofGetWidth()/2, ofGetHeight()/2, 700));

	// carga el modelo de ejemplo
	// importar desde Blender con eje -Z
	modelo.loadModel("modelo.3ds", true);

	botonPanel.setup("panel",0, "verde");
	botonPanelActivo = true;

	// setup del contenedor
	
	// inicializa cajas
	cajaTxt = cajaTexto(400,100, "Porcentaje de llamadas totales\n por números de clicks");
	cajaImg = cajaImagen(400,400, globales.imagenEstaticos);
	// envia cajas a contenedor
	
	guiEstatico.fila(cajaTxt.fbo);
	guiEstatico.fila(cajaImg.FboCajaImagen);
	guiEstatico.setup(400,400, "ESTATICO", true);
	
	
	
}


void Principal::draw(int _r, int _g, int _b) {
	ofBackgroundGradient(ofColor::white,globales.bgGris(), OF_GRADIENT_CIRCULAR);

	//ILUMINACION
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	ofEnableDepthTest();
	iluminacion.enable();
	
	


	cam.begin();
		ofPushMatrix();
			//http://www.openframeworks.cc/documentation/ofxAssimpModelLoader/ofxAssimpModelLoader.html
		modelo.draw(OF_MESH_FILL);
		ofPopMatrix();
	cam.end();

	ofDisableDepthTest();
	iluminacion.disable();
	ofDisableLighting();

	botonPanel.update(100,ofGetWindowHeight() -200);
	botonPanel.draw(0,0, 50);

	if(!botonPanelActivo)
		guiEstatico.draw(ofGetWidth() - 450,50);

	update();

	
}


void Principal::update(){

	if(botonPanelActivo){
		if(botonPanel.getter()) {
			guiEstatico.estados(true);
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
	guiEstatico.getter()? cam.disableMouseInput() : cam.enableMouseInput(); 


}

void Principal::activar() {
	botonPanel.estados(true);
	cam.enableMouseInput(); 

}
void Principal::desactivar() {
	botonPanel.estados(false);
	cam.disableMouseInput();

}






