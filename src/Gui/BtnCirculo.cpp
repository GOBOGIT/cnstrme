#include "btnCirculo.h"
#include "ofMain.h"

escena escenas;

void boton::setup() {
	esActivo = true;
}


void boton::setup(escena _escena, string _texto, ofTrueTypeFont _typo) {

	Relx = 0;
	Rely = 0;
	texto = _texto;
	typo = _typo;
	miescena = _escena;
	color = interf.cReleased();
	ofRegisterMouseEvents(this);
}

void boton::update(int _x, int _y) {
	Relx = _x;
	Rely = _y;
}

void boton::draw(int _x, int _y, int _r) {
	radio = _r;
	Absx =_x;
	Absy =_y;

	ofRectangle bounds = typo.getStringBoundingBox(texto, 0, 0);

	ofPushStyle();
		ofSetColor(color);
		ofCircle(Relx+Absx,Rely+Absy,radio);
		ofSetColor(ofColor::black);
		typo.drawString(texto,(Relx+Absx)-bounds.width/2,(Rely+Absy)+bounds.height/2);
	ofPopStyle();
	
}

void boton::mouseMoved(ofMouseEventArgs & args){}
void boton::mouseDragged(ofMouseEventArgs & args){}
void boton::mousePressed(ofMouseEventArgs & args){
	ofNotifyEvent(evento, texto,  this);

	if(dentro(args.x, args.y))
		color = interf.cClick();
	
}
void boton::mouseReleased(ofMouseEventArgs & args){

	if(dentro(args.x, args.y)){
		color = interf.cReleased();
		escenas = miescena;
	}
}


bool boton::dentro(float _x, float _y) {
	return(ofVec2f(_x,_y).distance(ofVec2f(Relx + Absx,Rely + Absy)) < radio);
}


void boton::estados(bool _estados) {

	if(_estados){
		color = interf.cReleased();
		ofRegisterMouseEvents(this);
	} else {
		color = interf.cDisable();
		ofUnregisterMouseEvents(this);
	}

}


