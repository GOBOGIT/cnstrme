#include "Boton.h"

boton::boton(tiposBotones _tipoBtn, string _colorBoton) {

	Relx = 0;
	Rely = 0;
	tipoBoton = _tipoBtn;
	escala = 1;
	colorBoton = _colorBoton;
	
	eventos =false;

	typo = Globales::tipografia["med"];
	typo.setLineHeight(18.0f); 
 	typo.setLetterSpacing(1.02); 

	estaDentro = false;
	isDrag = false;
	color = Globales::paqueteColores[colorBoton]["normal"];
	
}

void boton::update(int _x, int _y) {
	Relx = _x;
	Rely = _y;
}

// en caso de que sea un círculo
void boton::draw(ofVec2f _pos, int _r, string _texto) {
	
	texto = _texto;
	radio = _r;
	Absx =_pos.x;
	Absy =_pos.y;

	ofRectangle bounds = typo.getStringBoundingBox(texto, 0, 0);
	
	glPushMatrix();
		ofPushStyle();
			ofSetColor(color);
			glTranslatef(Relx+Absx,Rely+Absy,0);
			glScalef(escala, escala,0);
			ofCircle(0,0,radio);
			ofSetColor(ofColor::black);
			typo.drawString(texto,-bounds.width/2,bounds.height/2);
		ofPopStyle();
	glPopMatrix();
	
}

// CIRCULO CON IMAGEN
void boton::draw(ofVec2f _pos, int _diametro, ofImage _imagen) {

	radio = _diametro/2;
	Absx =_pos.x;
	Absy =_pos.y;

	imagen = _imagen;

	glPushMatrix();
		ofPushStyle();
			ofSetColor(color);
			glTranslatef(Relx+Absx,Rely+Absy,0);
			glScalef(escala, escala,0);
			imagen.draw(-radio,-radio,_diametro,_diametro);
		ofPopStyle();
	glPopMatrix();
	
	
}

// en caso de que sea rectángulo
void boton::draw(ofVec2f _pos, int _largo, int _ancho, string _texto) {

	texto = _texto;
	Absx =_pos.x;
	Absy =_pos.y;
	largo = _largo;
	ancho = _ancho;


	ofRectangle bounds = typo.getStringBoundingBox(texto, 0, 0);

	 posTextoX = (Relx+Absx) + (largo/2) -bounds.width/2;
	 posTextoY = (Rely+Absy) + (ancho /2)+bounds.height/2;

	ofPushStyle();
		ofSetColor(color);
		ofRect(Relx+Absx,Rely+Absy,largo, ancho);
		ofSetColor(ofColor::black);
		typo.drawString(texto,posTextoX,posTextoY);
	ofPopStyle();
}

// en caso de que sea rectángulo con imagen
void boton::draw(ofVec2f _pos, int _largo, int _ancho, ofImage _imagen) {

	Absx =_pos.x;
	Absy =_pos.y;
	largo = _largo;
	ancho = _ancho;
	imagen = _imagen;

	ofPushStyle();
		ofSetColor(color);
		imagen.draw(Relx+Absx,Rely+Absy,largo,ancho);
	ofPopStyle();
}

void boton::mouseMoved(ofMouseEventArgs & args){}
void boton::mouseDragged(ofMouseEventArgs & args){}
void boton::mousePressed(ofMouseEventArgs & args){
	//ofNotifyEvent(evento, texto,  this);
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
	
	if(tipoBoton == circuloImagen || tipoBoton == circuloTexto)
		//circulo;
		return(ofVec2f(_x,_y).distance(ofVec2f(Relx + Absx,Rely + Absy)) < radio);
	if(tipoBoton == rectImagen || tipoBoton ==rectTexto)
		return ((_x > Relx + Absx) && (_x < (Relx + Absx) + largo) && (_y > Rely + Absy) && (_y < Rely + Absy + ancho));

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

