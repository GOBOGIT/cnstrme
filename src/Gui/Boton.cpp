#include "Boton.h"

void boton::update(int _x, int _y) {
	// recoge el cambio de posicion o contenedor
	cout << _y<< endl;
	posicion = ofMatrix4x4::newTranslationMatrix(ofVec3f(_x,_y));
}

// en caso de que sea un círculo
void boton::draw(ofVec2f _pos, int _r, string _texto) {
	texto = _texto;
	radio = _r;
	ofRectangle bounds = typo.getStringBoundingBox(texto, 0, 0);
	origen = ofPoint(_pos);	// recoge origen del boton
	
	glPushMatrix();
		ofPushStyle();
			ofSetColor(color);
			//glScalef(escala, escala,0);
			ofCircle(origen,radio);	// en origen añadimos la posicion relativa del boton
			ofSetColor(ofColor::black);
			typo.drawString(texto,origen.x-bounds.width/2,origen.y+bounds.height/2);
		ofPopStyle();
	glPopMatrix();
}

// CIRCULO CON IMAGEN
void boton::draw(ofVec2f _pos, int _diametro, ofImage _imagen) {

	radio = _diametro/2;
	origen = ofPoint(_pos);	// recoge origen del boton
	imagen = _imagen;

	glPushMatrix();
		ofPushStyle();
			ofSetColor(color);
			//glScalef(escala, escala,0);
			imagen.draw(origen.x-radio,origen.y-radio,_diametro,_diametro);
		ofPopStyle();
	glPopMatrix();
}

// en caso de que sea rectángulo
void boton::draw(ofVec2f _pos, int _largo, int _ancho, string _texto) {

	texto = _texto;
	largo = _largo;
	ancho = _ancho;

	origen = ofPoint(_pos);	// recoge origen del boton
	ofRectangle bounds = typo.getStringBoundingBox(texto, 0, 0);

	 posTextoX = origen.x + (largo/2) -bounds.width/2;
	 posTextoY = origen.y + (ancho /2)+bounds.height/2;

	ofPushStyle();
		ofSetColor(color);
		ofRect(origen,largo, ancho);
		ofSetColor(ofColor::black);
		typo.drawString(texto,posTextoX,posTextoY);
	ofPopStyle();
}

// en caso de que sea rectángulo con imagen
void boton::draw(ofVec2f _pos, int _largo, int _ancho, ofImage _imagen) {

	largo = _largo;
	ancho = _ancho;
	imagen = _imagen;
	origen = ofPoint(_pos);	// recoge origen del boton

	ofPushStyle();
		ofSetColor(color);
		imagen.draw(origen,largo,ancho);
	ofPopStyle();
}

void boton::mouseMoved(ofMouseEventArgs & args){}
void boton::mouseDragged(ofMouseEventArgs & args){}
void boton::mousePressed(ofMouseEventArgs & args){
	if((dentro(args.x, args.y))){
		color = Globales::paqueteColores[colorBoton]["click"];
		escala = 0.9;
		estaDentro = false;
	}
}

void boton::mouseReleased(ofMouseEventArgs & args){
	if((dentro(args.x, args.y)) && !estaDentro){
		color = Globales::paqueteColores[colorBoton]["normal"];
		escala = 1;
		estaDentro = true;
	} else	if(!dentro(args.x,args.y)&& !estaDentro){
		color = Globales::paqueteColores[colorBoton]["normal"];
		escala = 1;
		estaDentro = false;
	}
}


bool boton::dentro(float _x, float _y) {
	if(tipoBoton == circuloImagen || tipoBoton == circuloTexto){
		// recoge el valor absoluto de la posición del boton
		ofPoint posAbsoluto= (origen * posicion);
		return(ofVec2f(_x,_y).distance(ofVec2f(posAbsoluto.x, posAbsoluto.y)) < radio);
	}
	if(tipoBoton == rectImagen || tipoBoton ==rectTexto){
		ofPoint posAbsoluto= (origen * posicion);
		return ((_x > posAbsoluto.x) && (_x < posAbsoluto.x + largo) && (_y > posAbsoluto.y) && (_y < posAbsoluto.y + ancho));
	}
}


void boton::estados(bool _estados) {
	if(_estados){
		color = Globales::paqueteColores[colorBoton]["normal"];
		if(!eventos) {
			ofRegisterMouseEvents(this);
			eventos = true;
		}
	} else {
	  color = Globales::paqueteColores[colorBoton]["disable"];
		if(eventos) {
			 ofUnregisterMouseEvents(this);
			eventos = false;
		}
	}
}