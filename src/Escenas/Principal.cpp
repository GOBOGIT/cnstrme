#include "Principal.h"


void Principal::iniciar(string _titulo) {
	titulo = _titulo;

	escena3D.setup();

	botonPanel = boton(boton::circuloTexto, "verde");
	botonPanelActivo = true;

	// inicializa cajas
	cajaCirculo = cajaGrCirculos(0,400,200,560,360,0.8,0.9, ofColor::darkGray);
	cajaTxt = cajaTexto(1,400,100, "Porcentaje de llamadas totales\npor numeros de clicks", ofColor::darkGrey, ofColor::white);
	otraCajaC = cajaGrCirculos(2,400,250,20,18,0.9,0.7, ofColor::darkGray);
	

	btnContenedor = boton(boton::circuloTexto,"verde");
	//cajaBtn = cajaBoton(3,400,100,50,"titulo", boton::circuloTexto,"verde");
	cajaBtn = cajaBoton(3,400,100,"jeje",btnContenedor);
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
	botonPanel.draw(ofVec2f(0,0), 50, "abrir");

	if(!botonPanelActivo)
		guiEstatico.draw(ofGetWindowWidth() - 450,50);

}

void Principal::update(){

	// recibe getter del boton del contenedor con id "caja"
	if(guiEstatico.cajasBotones["caja"].btn.getter()) {
		guiEstatico.cajasBotones["caja"].btn.setter(false);
		cout << "holaaa" << endl;
	}

	escena3D.update();
	//guiEstatico.update();
	botonPanel.update(100,ofGetWindowHeight() -200);
	
	if(botonPanelActivo){
		// abre cotnenedor
		if(botonPanel.getter()) {
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

void Principal::activar() {
	botonPanel.estados(true);
	escena3D.camara.enableMouseInput(); 

}
void Principal::desactivar() {
	botonPanel.estados(false);
	escena3D.camara.disableMouseInput();

}






