#pragma once

#include "ofMain.h"
#include "Escenas\inicio.h"
#include "Escenas\Principal.h"

class ofApp : public ofBaseApp{

	private:

		enum escena { inicio, principal, ventana };

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

		// Escenas disponibles
		escena escenas;
		Inicio escenaInicial;
		Principal escenaPrincipal;

		
		
};
