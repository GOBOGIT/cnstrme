#include "cajaTexto.h"


//extern desde ofApp
extern Globales globales;

cajaTexto::cajaTexto(int _largo, int _ancho, string _texto) {


	texto = _texto;
	largo = _largo;
	ancho = _ancho;

	titulo = globales.typo;
	titulo.setLineHeight(18.0f); 
 	titulo.setLetterSpacing(1.02); 

	FboCajaTexto.allocate(largo,ancho,GL_RGBA);
	FboCajaTexto.begin();
	ofPushStyle();
		ofFill();
		ofSetColor(globales.bgGris());
		ofRect(0,0,largo,ancho);
		ofSetColor(ofColor::black);
		titulo.drawStringAsShapes(texto,20,50);
		ofPopStyle();
	FboCajaTexto.end();
}



