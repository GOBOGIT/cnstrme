#include "btnCirculo.h"
#include "ofMain.h"


void boton::setup() {
	esActivo = true;
}


void boton::setup(escena _escena, string _texto, ofTrueTypeFont _typo) {

	texto = _texto;
	typo = _typo;
	miescena = _escena;
	color = interf.cReleased();
	ofRegisterMouseEvents(this);
}


void boton::draw(int _x, int _y, int _r) {
	radio = _r;
	x =_x;
	y =_y;
	

	ofRectangle bounds = typo.getStringBoundingBox(texto, 0, 0);

	ofPushStyle();
		ofSetColor(color);
		ofCircle(x,y,radio);
		ofSetColor(ofColor::black);
		typo.drawString(texto,x-bounds.width/2,y+bounds.height/2);
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
	return(ofVec2f(_x,_y).distance(ofVec2f(x,y)) < radio);
}

void boton::desactivar() {
	if(!esActivo) 
		ofUnregisterMouseEvents(this);
}

void boton::activar() {
	if(esActivo) 
		ofRegisterMouseEvents(this);
}
