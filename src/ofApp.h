#pragma once

#include "ofMain.h"
#include "Globales.h"
#include "Escenas\Loop.h"
#include "Escenas\Principal.h"
#include "Escenas\Galeria.h"
#include "Gui/GuiEscenas.h"
#include "Gui\Titulo.h"
#include "Rafaga.h"

extern Globales globales;

class ofApp : public ofBaseApp {

		Loop loop;
		Principal escenaPrincipal;
		Galeria escenaGaleria;
		GuiEscenas guiEscenas;
		Rafaga animRafaga;
		Titulo titulo;

		bool iniciaRafaga;
		string tituloEscena;

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		

		enum esc {inicio, principal, galeria} escenas;
		esc escenaSel;
		esc escenaRafaga;

		void estadosEscenas(bool, bool, bool);
		void selEscena(int, string);
		
		
		void rafaga(bool,esc, string);

		Globales globales;
		ofxTween tween;
		ofxEasingLinear easing;

};


