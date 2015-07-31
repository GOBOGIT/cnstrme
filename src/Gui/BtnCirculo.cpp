#include "btnCirculo.h"
#include "ofMain.h"


void boton::setup() {
	esActivo = true;
}

void boton::setup(escena _escena, string _texto) {
	
		texto = _texto;
		miescena = _escena;
		ofRegisterMouseEvents(this);
		
}



void boton::draw(int _x, int _y, int _r) {
	this->radio = _r;
	this ->x =_x;
	this ->y =_y;
	ofCircle(x,y,radio);
}


void boton::mouseMoved(ofMouseEventArgs & args){}
void boton::mouseDragged(ofMouseEventArgs & args){}
void boton::mousePressed(ofMouseEventArgs & args){
	ofNotifyEvent(evento, texto,  this);

	if(dentro(args.x, args.y)){
		cout << "dentro" + texto << endl;
		escenas = miescena;

	}
}
void boton::mouseReleased(ofMouseEventArgs & args){

		if(dentro(args.x, args.y)){
			cout << "released" << endl;
		}
}


bool boton::dentro(float _x, float _y) {
	return(ofVec2f(_x,_y).distance(ofVec2f(x,y)) < radio);
}

void boton::desactivar() {
	cout << "dentroDesact" + texto << endl;
	if(!esActivo)
		ofUnregisterMouseEvents(this);
}

void boton::activar() {
	cout << "dentroAct" + texto << endl;
	if(esActivo)
		ofRegisterMouseEvents(this);
}
