#include "GuiEstaticos.h"

// desde extern ofApp
extern Globales globales;

void GuiEstaticos::setup(int _largo, int _ancho, string _titulo, bool _btnSalida){

	largo = _largo;
	btnSalida = _btnSalida;
	textoTitulo = _titulo;
	estaDentro = false;
	iniciaAnim = false;
	
	ofRegisterMouseEvents(this);
	
	if(btnSalida)	botonSalir.setup("X",1, "rojo");
	titulo = globales.typo;
	
	barra = 40;
	anchoFinal = barra;
	
	posyFila.push_back(barra);

	for(unsigned int i = 0; i < filas.size(); i++) {
		anchoFinal += filas[i].getHeight();
		posyFila.push_back(anchoFinal);
	}
};


void GuiEstaticos::draw(int _posx, int _posy){

	posx = _posx;
	if(iniciaAnim) {
		posy = _posy + animacionContenedor.update();
		if(animacionContenedor.isCompleted())
			iniciaAnim = false;
	}

	//anchoFinal = barra + FboTexto.getHeight() + FboImagen.getHeight() + FboVideo.getHeight();
	//unsigned int anterior;

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
			

			for(unsigned int i = 0; i < filas.size(); i++) {
				filas[i].draw(0,posyFila[i], largo, filas[i].getHeight());
			}
			
		ofPopStyle();
	ofPopMatrix();
	
	if(btnSalida) {
		botonSalir.update(posx,posy);
		botonSalir.draw(0,posyFila.back(),largo,50);
	}

}
void GuiEstaticos::update(){};




void GuiEstaticos::fila(ofFbo _Fbo) {
	filas.push_back(_Fbo);
}


void GuiEstaticos::mouseMoved(ofMouseEventArgs & args){}
void GuiEstaticos::mouseDragged(ofMouseEventArgs & args){}
void GuiEstaticos::mousePressed(ofMouseEventArgs & args){
		if(dentro(args.x, args.y))	estaDentro = true;

}
void GuiEstaticos::mouseReleased(ofMouseEventArgs & args){
		if(dentro(args.x, args.y))	estaDentro = false;
}

bool GuiEstaticos::dentro(float _x, float _y) {
	return ((_x > posx) && (_x < posx + largo) && (_y > posy) && (_y < posy + anchoFinal));
}

bool GuiEstaticos::getter() {
	return estaDentro;
}

void GuiEstaticos::estados(bool _estado){

if(_estado)
	iniciaAnim = true;
	animacion();

};

void GuiEstaticos::animacion() {
	animacionContenedor.setParameters(1,easinglinear,ofxTween::easeOut, 0,-10,200,0);
}