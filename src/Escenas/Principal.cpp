#include "Principal.h"


void Principal::setup() {

	botonPanelActivo = true;
	escena3D.setup();

	botonPanel.setup(boton::circuloTexto, "verde");

	// inicializa cajas
	cajaCirculo = cajaGrCirculos(0,400,200,560,360,0.8,0.9, ofColor::darkGray);
	cajaTxt = cajaTexto(1,400,100, "Porcentaje de llamadas totales\npor numeros de clicks", ofColor::darkGrey, ofColor::white);
	otraCajaC = cajaGrCirculos(2,400,250,20,18,0.9,0.7, ofColor::darkGray);
	btnContenedor.setup(boton::rectTexto,"verde");

	cajaBtn = cajaBoton(3,400,100,"prueba", btnContenedor);
	// necesario para regresar los getters
	cajaBtn.id ="caja";
	
	// envia cajas a contenedor
	guiEstatico.fila(cajaCirculo);
	guiEstatico.fila(cajaTxt);
	guiEstatico.fila(otraCajaC);
	guiEstatico.fila(cajaBtn);
	guiEstatico.setup(400,560, "ESTATICO", true, false);

}


void Principal::draw(int _r, int _g, int _b) {
	ofBackgroundGradient(ofColor::white,Globales::color["gris220"], OF_GRADIENT_CIRCULAR);
	
	escena3D.draw();
	botonPanel.draw(ofVec2f(90,600), 50,"panel");


	
	if(!botonPanelActivo) {
		guiEstatico.draw(ofGetWindowWidth() - 450,50);
	}

}

void Principal::update(){

	// recibe getter del boton del contenedor con id "caja"
	if(guiEstatico.cajasBotones["caja"].btn->getter()) {
		guiEstatico.cajasBotones["caja"].btn->setter(false);
		cout << "holaaa" << endl;
	}

	escena3D.update();
	
	if(botonPanelActivo){
		// abre cotnenedor
		if(botonPanel.getter()) {
			cout << "entrabtn" << endl;
			guiEstatico.estados(true);	// bloquea / activa el boton, tipo checkbox
			botonPanelActivo = false;
			botonPanel.setter(false);
			escena3D.setter("Caja", true);
		}
		botonPanel.estados(true);
	} else {
		// cierra contenedor
		botonPanel.estados(false);
		
		if(guiEstatico.botonSalir.getter()){
			guiEstatico.botonSalir.setter(false);
			botonPanelActivo = true;
			escena3D.setter("Caja", false);
		}
	}

	guiEstatico.getter()?  escena3D.camara.disableMouseInput() : escena3D.camara.enableMouseInput(); 


}

void Principal::estados(bool _estado) {
	if(_estado) {
		botonPanel.estados(true);
		escena3D.camara.enableMouseInput(); 
	} else {
		botonPanel.estados(false);
		escena3D.camara.disableMouseInput();
	}
}








