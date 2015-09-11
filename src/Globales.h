#pragma once
#include "ofMain.h"
#include "ofxJSON.h"

class Globales {


	public:

		static map<string,ofImage> iconos;
		static map<string,ofImage> imagenes;
		static map<string,ofTrueTypeFont> tipografia;
		static map<string, ofVideoPlayer> videoPlayer;

		static map<string, map<string, ofColor>> paqueteColores;
		static map<string, ofColor> color;

		void assets();
		//void setup();

		//importa los elementos desde un archivo JSON
		ofxJSONElement json;

		string nombreTipografia;
		int sizeTipo;

		/* stringstream &ss; */
		string archivo;
		bool parsingOk;	
};


