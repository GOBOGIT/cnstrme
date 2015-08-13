#include "GuiEstaticos.h"

// desde extern ofApp
extern Globales globales;

void GuiEstaticos::setup(int _largo, int _ancho, string _titulo){

	largo = _largo;
	//ancho = _ancho;
	estaDentro = false;
	ofRegisterMouseEvents(this);
	botonSalir.setup("Salir",1);
	titulo = globales.typo;
	textoTitulo = _titulo;
	barra = 40;
	
};


void GuiEstaticos::draw(int _posx, int _posy){

	posx = _posx;
	posy = _posy;
	
	anchoFinal = barra + FboTexto.getHeight() + FboImagen.getHeight();
	

	ofPushMatrix();
	ofTranslate(posx,posy);
		ofPushStyle();
			ofFill();	
			ofSetColor(ofColor::darkGray);
			ofRect(0,0,largo,barra);
			ofSetColor(ofColor::white);
			titulo.drawStringAsShapes(textoTitulo,10,barra-12);
			ofSetColor(ofColor::white);
			ofRect(0,barra,largo,anchoFinal);

			FboTexto.draw(0,barra,largo, anchoCajaTexto);
			FboImagen.draw(0,barra + FboTexto.getHeight(),largo, anchoCajaImagen);
		ofPopStyle();

	ofPopMatrix();

	
			
	botonSalir.update(posx,posy);
	botonSalir.draw(0,anchoFinal,largo,50);

}

void GuiEstaticos::update(){};
void GuiEstaticos::estados(bool _estado){};



void GuiEstaticos::cajaTexto(ofFbo _Fbo) {
	FboTexto = _Fbo;
	anchoCajaTexto = FboTexto.getHeight();

}


void GuiEstaticos::cajaImagen(ofFbo _Fbo) {
	FboImagen = _Fbo;
	anchoCajaImagen = FboImagen.getHeight();

}


void GuiEstaticos::mouseMoved(ofMouseEventArgs & args){}
void GuiEstaticos::mouseDragged(ofMouseEventArgs & args){}
void GuiEstaticos::mousePressed(ofMouseEventArgs & args){
		if(dentro(args.x, args.y)){
			cout << "esta dentro" << endl;
			estaDentro = true;
	}
}
void GuiEstaticos::mouseReleased(ofMouseEventArgs & args){
		if(dentro(args.x, args.y))
			estaDentro = false;
}

bool GuiEstaticos::dentro(float _x, float _y) {
	// rectangulo
	return ((_x > posx) && (_x < posx + largo) && (_y > posy) && (_y < posy + anchoFinal));
}

bool GuiEstaticos::getter() {
	return estaDentro;
}