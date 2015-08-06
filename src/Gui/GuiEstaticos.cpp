#include "GuiEstaticos.h"

void GuiEstaticos::setup(){


};


void GuiEstaticos::draw(int _posx, int _posy, int _largo, int _ancho){

	posx = _posx;
	posy = _posy;
	largo = _largo;
	ancho = _ancho;

	ofPushMatrix();
	ofTranslate(posx,posy);
		ofPushStyle();
			ofSetColor(ofColor::white);
			ofFill();
			ofRect(0,0,largo,ancho);
			ofPopStyle();
	ofPopMatrix();

}

void GuiEstaticos::update(){

	

};
void GuiEstaticos::estados(bool _estado){



};