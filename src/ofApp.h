#pragma once

#include "ofMain.h"

#include "Globales.h"
#include "Escenas\Loop.h"
#include "Escenas\Principal.h"
#include "Escenas\Galeria.h"
#include "Gui/GuiEscenas.h"
#include "Gui/Titulo.h"
#include "Rafaga.h"

// contenedor y cajas para las rafagas
#include "Gui/Contenedor.h"
#include "Cajas\cajaImagen.h"
#include "Cajas\cajaGR_Circulos.h"
#include "Cajas\cajaAnim.h"

extern Globales globales;

class ofApp : public ofBaseApp {

		Loop loop;
		Principal escenaPrincipal;
		Galeria escenaGaleria;
		GuiEscenas guiEscenas;
		//Rafaga animRafaga;
		Titulo titulo;
		
		enum esc {inicio, principal, galeria} escenas;
		struct escena {
			Principal escenaPrincipal;
			Galeria escenaGaleria;
			GuiEscenas guiEscenas;

			esc tipoEscena;
			string titulo;
			bool estado;
		};
		map<string, escena> listaEscenas;
		// creacion de rafagas
		
		Contenedor contenedor[2];
		//vector <Contenedor> contenedores;
		map<string, Contenedor> ContenedoresRafagas;
		//Contenedor ContenedoresRafagas;
		Rafaga RafagaSel;
		map<string, Rafaga> rafagas;
		
		bool iniciaRafaga;

		// titulo de la escena
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
		
		// escebas
		
		esc escenaSel;
		esc escenaRafaga;

		// cada bool define el estado de cada escena del enum anterior
		void estadosEscenas(bool, bool, bool);
		void selEscena(int, string);
		
		
		void rafaga(esc, string);
		void rafaga(Rafaga, esc, string);

		Globales globales;
		ofxTween tween;
		ofxEasingLinear easing;

};


