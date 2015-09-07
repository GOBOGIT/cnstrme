#include "cajaGR_Circulos.h"

#define RESOLUCION 64.

cajaGrCirculos::cajaGrCirculos( unsigned int _posFila,int _w, int _h, float _vMax, float _vFinal, float _escalaCirculo, float _escalaInterior, ofColor _bg, ofColor _fg) {
	w = _w;
	h = _h;
	vMax = _vMax;
	vFinal = _vFinal;
	posFila = _posFila;
	escalaInterior = _escalaInterior;
	bg = _bg;
	fg = _fg;
	escalaCirculo = _escalaCirculo;
	porcentajeFinal = (360 * vFinal) / vMax;
	resolucion = RESOLUCION;
	radio = (min(w,h)/2) * escalaCirculo;
	iniciar = false;
	valorTween = 1.0f;
	valores =  Globales::tipografia["med"];
}


void cajaGrCirculos::update() {

		if(iniciar) {
		valorTween = anim.update();
			if(anim.isCompleted()){
				iniciar = false;
			}
		} 
			
}

void cajaGrCirculos::iniciaAnim() {
		
		iniciar = true;
		valorTween = 1.0f;
		anim.setParameters(1,easingBounce,ofxTween::easeOut, 1, porcentajeFinal, 1200,0);
}

void cajaGrCirculos::draw() {
		
		int porcentajeEnNum = (vMax * valorTween) / 360;
		ofPath path = ofPath();
		string texto = ofToString(int(porcentajeEnNum))+" / "+ofToString(int(vMax));
		ofRectangle bounds = valores.getStringBoundingBox(texto, 0, 0);

			ofPushMatrix();
				ofPushStyle();
				ofSetColor(bg);
					ofRect(0,0,w,h);		
					path.setMode(ofPath::POLYLINES);  
							path.setFilled(true);
							path.setCircleResolution(RESOLUCION);
							path.setFillColor(fg);
							path.moveTo((w/2),(h/2));
							path.arc((w/2),(h/2),radio,radio,0,valorTween);
							path.draw();
							ofSetColor(bg);

							ofCircle((w/2),(h/2),radio*escalaInterior);
							ofSetColor(fg);
							valores.drawString(texto,(w/2)-(bounds.width/2),h/2);
				ofPopStyle();
			ofPopMatrix();
}