#include "Principal.h"
//#include "../3D/3DLoader.h"


// desde extern ofapp
extern Globales globales;

void Principal::iniciar(string _titulo) {
	titulo = _titulo;

	escena3D.setup();

	botonPanel.setup("panel",0, "verde");
	botonPanelActivo = true;

	// inicializa cajas
	cajaTxt = cajaTexto(400,100, "Porcentaje de llamadas totales\npor numeros de clicks", ofColor::darkGrey, ofColor::white, 1);
	cajaCirculo = cajaGrCirculos(0,400,200,560,360,0.8,0.9, ofColor::darkGray);
	otraCajaC = cajaGrCirculos(2,400,250,20,18,0.9,0.7, ofColor::darkGray);
	// envia cajas a contenedor
	
	guiEstatico.fila(cajaCirculo);
	guiEstatico.fila(cajaTxt);
	guiEstatico.fila(otraCajaC);
	guiEstatico.setup(400,560, "ESTATICO", true, false);
}


void Principal::draw(int _r, int _g, int _b) {
	ofBackgroundGradient(ofColor::white,globales.bgGris(), OF_GRADIENT_CIRCULAR);
	
	escena3D.draw();

	botonPanel.update(100,ofGetWindowHeight() -200);
	botonPanel.draw(0,0, 50);

	if(!botonPanelActivo)
		guiEstatico.draw(ofGetWindowWidth() - 450,50);

	update();

}

void Principal::update(){
		escena3D.update();
		
		guiEstatico.update();
		//cajaCirculo.update();
	
		if(botonPanelActivo){
		// abre cotnenedor
		if(botonPanel.getter()) {
			guiEstatico.estados(true);
			botonPanelActivo = false;
			botonPanel.setter(false);
			//guiEstatico.cajaC.iniciaAnim();
			escena3D.setter("cubo0", true);
		}
		botonPanel.estados(true);
	} else {
		// cierra contenedor
		botonPanel.estados(false);
		
		if(guiEstatico.botonSalir.getter()){
			guiEstatico.botonSalir.setter(false);
			botonPanelActivo = true;
			escena3D.setter("cubo0", false);
		}
	}

	// revisar, problemas con el mouse
	guiEstatico.getter()?  escena3D.camara.disableMouseInput() : escena3D.camara.enableMouseInput(); 


}

void Principal::activar() {
	botonPanel.estados(true);
	escena3D.camara.enableMouseInput(); 

}
void Principal::desactivar() {
	botonPanel.estados(false);
	escena3D.camara.disableMouseInput();

}






