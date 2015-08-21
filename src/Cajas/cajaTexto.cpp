#include "cajaTexto.h"


//extern desde ofApp
extern Globales globales;

cajaTexto::cajaTexto(int _largo, int _ancho, string _texto, ofColor _colorFondo, ofColor _colorTexto) {


	texto = _texto;
	largo = _largo;
	ancho = _ancho;
	colorFondo = _colorFondo;
	colorTexto = _colorTexto;

	titulo = globales.typo;
	titulo.setLineHeight(18.0f); 
 	titulo.setLetterSpacing(1.02); 
	ofRectangle bounds = titulo.getStringBoundingBox(texto, 0, 0);

	fbo.allocate(largo,ancho,GL_RGBA);
	fbo.begin();
	ofPushStyle();
		ofFill();
		ofSetColor(colorFondo);
		ofRect(0,0,largo,ancho);
		ofSetColor(colorTexto);
		titulo.drawString(texto,15,(ancho/2));
		ofPopStyle();
	fbo.end();
}



