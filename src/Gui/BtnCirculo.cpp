#include "btnCirculo.h"

#include "ofMain.h"


// desde extern en ofapp
extern Globales globales;

void boton::setup(string _texto, int  _tipo) {

	Relx = 0;
	Rely = 0;
	tipoBoton = _tipo;

	typo.setLineHeight(18.0f); 
 	typo.setLetterSpacing(1.02); 

	texto = _texto;
	typo = globales.typo;
	estaDentro = false;
	color = globales.cReleased();
	ofRegisterMouseEvents(this);
}

void boton::update(int _x, int _y) {
	Relx = _x;
	Rely = _y;
}


// en caso de que sea un círculo
void boton::draw(int _x, int _y, int _r) {
	radio = _r;
	Absx =_x;
	Absy =_y;


	ofRectangle bounds = typo.getStringBoundingBox(texto, 0, 0);

	ofPushStyle();
		ofSetColor(color);
		ofCircle(Relx+Absx,Rely+Absy,radio);
		ofSetColor(ofColor::black);
		typo.drawStringAsShapes(texto,(Relx+Absx)-bounds.width/2,(Rely+Absy)+bounds.height/2);
	ofPopStyle();
	
}

// en caso de que sea rectángulo
void boton::draw(int _x, int _y, int _largo, int _ancho) {

	Absx =_x;
	Absy =_y;
	largo = _largo;
	ancho = _ancho;

	ofRectangle bounds = typo.getStringBoundingBox(texto, 0, 0);

	 posTextoX = (Relx+Absx) + (largo/2) -bounds.width/2;
	 posTextoY = (Rely+Absy) + (ancho /2)+bounds.height/2;

	ofPushStyle();
		ofSetColor(color);
		ofRect(Relx+Absx,Rely+Absy,largo, ancho);
		ofSetColor(ofColor::black);
		typo.drawStringAsShapes(texto,posTextoX,posTextoY);
	ofPopStyle();
}

void boton::mouseMoved(ofMouseEventArgs & args){}
void boton::mouseDragged(ofMouseEventArgs & args){}
void boton::mousePressed(ofMouseEventArgs & args){
	//ofNotifyEvent(evento, texto,  this);
	if((dentro(args.x, args.y)) && !estaDentro){
		color = globales.cClick();
		estaDentro = true;
	}
	
}
void boton::mouseReleased(ofMouseEventArgs & args){

	if((dentro(args.x, args.y)) && estaDentro){
		color = globales.cReleased();
		estaDentro = false;
	}
}


bool boton::dentro(float _x, float _y) {
	
	if(tipoBoton == 0)
		return(ofVec2f(_x,_y).distance(ofVec2f(Relx + Absx,Rely + Absy)) < radio);
	if(tipoBoton == 1)
		return ((_x > Relx + Absx) && (_x < (Relx + Absx) + largo) && (_y > Rely + Absy) && (_y < Rely + Absy + ancho));

}


void boton::estados(bool _estados) {

	if(_estados){
		color = globales.cReleased();
		ofRegisterMouseEvents(this);
	} else {
		color = globales.cDisable();
		ofUnregisterMouseEvents(this);
	}

}

bool boton::getter() {
	return estaDentro;
}

void boton::setter(bool _dentro) {
	estaDentro = _dentro;
}


