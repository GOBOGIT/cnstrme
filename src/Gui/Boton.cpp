#include "Boton.h"

//#include "ofMain.h"


// desde extern en ofapp
extern Globales globales;


void boton::setup(string _texto, int  _tipo, string _colorBoton) {

	Relx = 0;
	Rely = 0;
	tipoBoton = _tipo;
	escala = 1;
	colorBoton = _colorBoton;

	typo.setLineHeight(18.0f); 
 	typo.setLetterSpacing(1.02); 

	texto = _texto;
	typo = globales.typo;
	estaDentro = false;
	color = globales.paqueteColores[colorBoton]["normal"];
	ofRegisterMouseEvents(this);


	// en botones con imagenes
	imagen.loadImage("uvtemplate.jpg");
    fboImagen.allocate(imagen.width, imagen.height);
    fboMascara.allocate(imagen.width, imagen.height);
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
void boton::draw(int _x, int _y, int _r, ofImage _imagen) {
	radio = _r;
	Absx =_x;
	Absy =_y;
	
	glPushMatrix();
		ofPushStyle();
			 ofSetColor(255, 255, 255);
			
			glTranslatef(Relx+Absx,Rely+Absy,0);
			glScalef(escala, escala,0);

			fboImagen.begin();
				ofClear(0,0,0,0);
				ofSetColor(color);
				imagen.draw(0,0);
			fboImagen.end();

			fboMascara.begin();
				ofClear(0,0,0,0);
				ofSetColor(255,255,255);
				ofCircle(0,0,radio);
			fboMascara.end();

			
			fboMascara.draw(0,0);
			ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
			fboImagen.draw(-imagen.getWidth()/2,-imagen.getHeight()/2);
			ofDisableBlendMode();
			
		ofPopStyle();
	glPopMatrix();
	
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
		typo.drawString(texto,posTextoX,posTextoY);
	ofPopStyle();
}

void boton::mouseMoved(ofMouseEventArgs & args){}
void boton::mouseDragged(ofMouseEventArgs & args){}
void boton::mousePressed(ofMouseEventArgs & args){
	//ofNotifyEvent(evento, texto,  this);
	if((dentro(args.x, args.y))){
		color = globales.paqueteColores[colorBoton]["click"];
		escala = 0.9;
		estaDentro = false;
	}
	
}
void boton::mouseReleased(ofMouseEventArgs & args){

	if((dentro(args.x, args.y)) && !estaDentro){
		color = globales.paqueteColores[colorBoton]["normal"];
		escala = 1;
		estaDentro = true;
		
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
		color = globales.paqueteColores[colorBoton]["normal"];
		
		ofRegisterMouseEvents(this);
	} else {
	  color = globales.paqueteColores[colorBoton]["disable"];
		ofUnregisterMouseEvents(this);
	}

}

