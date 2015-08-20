#include "Principal.h"
//#include "../3D/3DLoader.h"


// desde extern ofapp
extern Globales globales;

void Principal::iniciar() {

	// setup de la camara
	//cam.setPosition(ofPoint(ofGetWidth()/2, ofGetHeight()/2, 700));

	// carga el modelo de ejemplo
	// importar desde Blender con eje -Z
	//modelo.loadModel("modelo.3ds", true);

	escena3D.setup();

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

	
	escena3D.draw();


	botonPanel.update(100,ofGetWindowHeight() -200);
	botonPanel.draw(0,0, 50);

	if(!botonPanelActivo)
		guiEstatico.draw(ofGetWidth() - 450,50);

	update();

	
}

void Principal::update(){
		escena3D.update();
	

	if(botonPanelActivo){
		// abre cotnenedor
		if(botonPanel.getter()) {
			guiEstatico.estados(true);
			botonPanelActivo = false;
			botonPanel.setter(false);
			escena3D.setter("Cubo0", true);
		}
		botonPanel.estados(true);
	} else {
		// cierra contenedor
		botonPanel.estados(false);
		
		if(guiEstatico.botonSalir.getter()){
			guiEstatico.botonSalir.setter(false);
			botonPanelActivo = true;
			escena3D.setter("Cubo0", false);
		}
	}

	// revisar, problemas con el mouse
	guiEstatico.getter()? escena3D.camara.disableMouseInput() : escena3D.camara.enableMouseInput(); 


}

void Principal::activar() {
	botonPanel.estados(true);
	escena3D.camara.enableMouseInput(); 

}
void Principal::desactivar() {
	botonPanel.estados(false);
	escena3D.camara.disableMouseInput();

}






