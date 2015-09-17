#include "Contenedor.h"

#define ANCHO_BARRA 40.

void Contenedor::setup(int _largo, int _ancho, string _titulo, bool _btnSalida, bool _barra){

	largo = _largo;
	btnSalida = _btnSalida;
	textoTitulo = _titulo;
	b_barra = _barra;

	estaDentro = false;
	iniciaAnim = false;
	eventos =false;
	posyFinal = 0;


	if(btnSalida)
		botonSalir.setup(boton::rectImagen,"rojo");

	titulo = Globales::tipografia["med"];

	if(b_barra) 
		barra = ANCHO_BARRA;
	else
		barra = 0;

	anchoFinal =0;
	posyFila.push_back(barra);

	for(unsigned int i : anchoCaja) {
		anchoFinal += i;
		posyFila.push_back(anchoFinal);
	}
};

void Contenedor::draw(float _posx, float _posy){
	posx = _posx;
	if(iniciaAnim) {
		posyFinal = animacionContenedor.update();
		posy= _posy + posyFinal;

		if(animacionContenedor.isCompleted())
			iniciaAnim = false;
	} else{
		posy = _posy + posyFinal;
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

	for(cajaGrCirculos &cajaSel : cajasCirculos) {	
			if(!cajasCirculos.empty() && cajaSel.posFila == i){
				
				if(iniciaAnim){
					cajaSel.iniciaAnim();
					cout << "anim circulos" + ofToString(iniciaAnim) << endl;
				}
				cajaSel.draw();
				cajaSel.update();
			}
		}

		for(cajaTexto &cajaSel : cajasTexto) {	
			if(!cajasTexto.empty() && cajaSel.posFila == i)	cajaSel.draw();
		}

		for(cajaImagen &cajaSel : cajasImagen) {	
			if(!cajasImagen.empty() && cajaSel.posFila == i) cajaSel.draw();
		}

		for(cajaAnim &cajaSel : cajasVideo) {	
			if(!cajasVideo.empty() && cajaSel.posFila == i){
				cajaSel.draw();
				cajaSel.update();
			}
		}


		map<string, cajaBoton>::iterator it;
		for(it = cajasBotones.begin(); it!= cajasBotones.end(); it++){
			if(!cajasBotones.empty() && it->second.posFila == i) {
				ofPushMatrix();
				ofTranslate(-posx,-(posy+posyFila[i]),0);				// invierte la posicion global
				it->second.draw(posx,posy+posyFila[i]);					// ajusta la posición si se desea
				ofPopMatrix();
			}
		} 
		ofPopMatrix();
	}
	ofPopStyle();
	ofPopMatrix();



	if(btnSalida) 
		botonSalir.draw(ofVec2f(posx,anchoFinal +posy),largo,50,Globales::iconos["cerrar400x50"]);


}
void Contenedor::update(int _posx, int _posy){

	map<string, cajaBoton>::iterator it;
	for(it = cajasBotones.begin(); it!= cajasBotones.end(); it++){
		if(!cajasBotones.empty()) it->second.btn->update(_posx, _posy); 
	} 
};


void Contenedor::fila(cajaGrCirculos &_caja) {
	cajasCirculos.push_back(_caja);
	anchoCaja.push_back(_caja.h);
}

void Contenedor::fila(const cajaTexto &_caja) {
	cajasTexto.push_back(_caja);
	anchoCaja.push_back(_caja.h);
}

void Contenedor::fila(cajaImagen &_caja) {
	cajasImagen.push_back(_caja);
	anchoCaja.push_back(_caja.h);
}

void Contenedor::fila(cajaBoton &_caja) {
	// en este caso es un MAP, para poder ecoger los getter por nombre del objeto
	cajasBotones.emplace(_caja.id, move(_caja));
	//cajasBotones[_caja.id] = _caja;
	anchoCaja.push_back(_caja.h);
}

void Contenedor::fila(cajaAnim &_caja) {
	cajasVideo.push_back(_caja);
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


void Contenedor::estados(bool _estado){
	if(_estado) {
		if(!eventos) {
			ofRegisterMouseEvents(this);
			eventos = true;
		}
		
		// activa los botones
		map<string, cajaBoton>::iterator it;
		for(it = cajasBotones.begin(); it!= cajasBotones.end(); it++){
			if(!cajasBotones.empty()) it->second.estados(true); 
		}



		// reproduce el video al abrir el contenedor
		for(cajaAnim &cajaSel : cajasVideo) {	
			if(!cajasVideo.empty()) cajaSel.video->play();
		}

		
		botonSalir.estados(true);
		iniciaAnim = true;
		animacion();

	} else {
		if(eventos) {
			ofUnregisterMouseEvents(this);
			eventos =false;
		}
		botonSalir.estados(false);

		// para y reinicia a primer frame el video
		for(cajaAnim &cajaSel : cajasVideo) {	
			if(!cajasVideo.empty()){ 
				cajaSel.video->stop();
				cajaSel.video->setPosition(0);
			}
		}
	}
};

void Contenedor::animacion() {
	animacionContenedor.setParameters(1,easinglinear,ofxTween::easeOut, 0,-10,200,0);
}