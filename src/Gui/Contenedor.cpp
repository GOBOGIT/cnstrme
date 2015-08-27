#include "Contenedor.h"

// desde extern ofApp
extern Globales globales;

void Contenedor::setup(int _largo, int _ancho, string _titulo, bool _btnSalida, bool _barra){

	largo = _largo;
	btnSalida = _btnSalida;
	textoTitulo = _titulo;
	b_barra = _barra;
	estaDentro = false;
	iniciaAnim = false;
	
	ofRegisterMouseEvents(this);
	
	if(btnSalida) {
		botonSalir.setup("X",1, "rojo");
	}
	titulo = globales.typo;
	
	if(b_barra) 
		barra = 40;
	else
		barra = 0;

		anchoFinal =0;
		posyFila.push_back(barra);

		for(unsigned int i = 0; i < anchoCaja.size(); i++) {
		anchoFinal += anchoCaja[i];
		posyFila.push_back(anchoFinal);
	
	}
			
		
};


void Contenedor::draw(int _posx, int _posy){
//	ofEnableSmoothing();

	posx = _posx;
	if(iniciaAnim) {
		posy = _posy + animacionContenedor.update();
		if(animacionContenedor.isCompleted())
			iniciaAnim = false;
	}

	ofPushMatrix();
	ofTranslate(posx,posy);
		ofPushStyle();
			ofFill();	
			
			if(b_barra){
				ofSetColor(ofColor::darkGray);
				ofRect(0,0,largo,barra);
			
			ofSetColor(ofColor::white);
			titulo.drawString(textoTitulo,10,barra-12);
			}
			ofSetColor(ofColor::white);
			ofRect(0,barra,largo,anchoFinal);

			
		for(unsigned int i = 0; i < anchoCaja.size(); i++) {
			ofPushMatrix();
			ofTranslate(0,posyFila[i]);
			for(unsigned int ii = 0; ii < stFilas.cajasCirculos.size(); ii++) {	
				if(!stFilas.cajasCirculos.empty() && stFilas.cajasCirculos[ii].posFila == i){
					//ofPopMatrix();
					//ofTranslate(0,posyFila[i]);
					if(iniciaAnim) stFilas.cajasCirculos[ii].iniciaAnim();
					stFilas.cajasCirculos[ii].draw();
					stFilas.cajasCirculos[ii].update();
	
				}
			}
			
			for(unsigned int aa = 0; aa < stFilas.cajasTexto.size(); aa++) {	
			if(!stFilas.cajasTexto.empty() && stFilas.cajasTexto[aa].posFila == i){
			//	ofTranslate(0,posyFila[i]);	
				stFilas.cajasTexto[aa].draw();
					
				}
			}
		
			for(unsigned int bb = 0; bb < stFilas.cajasImagen.size(); bb++) {	
			if(!stFilas.cajasImagen.empty() && stFilas.cajasImagen[bb].posFila == i){
			//	ofTranslate(0,posyFila[i]);		
				stFilas.cajasImagen[bb].draw();
					
				}
			}
			ofPopMatrix();
		
		
		}
			ofPopStyle();
	ofPopMatrix();
	


	if(btnSalida) {
		botonSalir.update(posx,posy);
		botonSalir.draw(0,anchoFinal,largo,50);
	}

}
void Contenedor::update(){
//	if(!stFilas.cajasCirculos.empty()) {
		//	stFilas.cajasCirculos[0].update();

//	}
};


void Contenedor::fila(cajaGrCirculos _caja) {
	stFilas.cajasCirculos.push_back(_caja);
	anchoCaja.push_back(_caja.h);
}

void Contenedor::fila(cajaTexto _caja) {
	stFilas.cajasTexto.push_back(_caja);
	anchoCaja.push_back(_caja.h);
}

void Contenedor::fila(cajaImagen _caja) {
	stFilas.cajasImagen.push_back(_caja);
	anchoCaja.push_back(_caja.h);
}



void Contenedor::mouseMoved(ofMouseEventArgs & args){}
void Contenedor::mouseDragged(ofMouseEventArgs & args){}
void Contenedor::mousePressed(ofMouseEventArgs & args){
		if(dentro(args.x, args.y))	estaDentro = true;

}
void Contenedor::mouseReleased(ofMouseEventArgs & args){
		if(dentro(args.x, args.y))	estaDentro = false;
}

bool Contenedor::dentro(float _x, float _y) {
	return ((_x > posx) && (_x < posx + largo) && (_y > posy) && (_y < posy + anchoFinal));
}

bool Contenedor::getter() {
	return estaDentro;
}

void Contenedor::estados(bool _estado){

if(_estado)
	iniciaAnim = true;
	animacion();

//	if(!stFilas.cajasCirculos.empty())
//		stFilas.cajasCirculos[0].iniciaAnim();

};

void Contenedor::animacion() {
	animacionContenedor.setParameters(1,easinglinear,ofxTween::easeOut, 0,-10,200,0);
}