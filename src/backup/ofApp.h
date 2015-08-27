#pragma once

#include "ofMain.h"
#include "Globales.h"
#include "Escenas\Inicio.h"
#include "Escenas\Principal.h"
#include "Escenas\Galeria.h"
#include "Gui/GuiEscenas.h"
#include "Gui\Titulo.h"
#include "Rafaga.h"

extern Globales globales;

class ofApp : public ofBaseApp {

		Inicio escenaInicial;
		Principal escenaPrincipal;
		Galeria escenaGaleria;
		GuiEscenas guiEscenas;
		Rafaga rafaga;
		Titulo titulo;

		struct escena {
			Inicio escenaInicial;
			bool esrafaga;
		};

		bool rafagaEstado;
		bool activaCambioEscena;
		bool rafagaActivada;

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

		void estadosEscenas(bool, bool, bool);
		void selEscena(int);



};


