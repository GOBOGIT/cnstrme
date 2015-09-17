#pragma once
#include "ofMain.h"
#include "ofxJSON.h"
#include "ofxHapPlayer.h"

class Globales : public ofBaseApp{


	public:

		static map<string,ofImage> iconos;
		static map<string,ofImage> imagenes;
		static map<string,ofTrueTypeFont> tipografia;
		static map<string, ofVideoPlayer*> videoPlayer;
		static map<string, ofxHapPlayer*> videoHap;

		static map<string, map<string, ofColor>> paqueteColores;
		static map<string, ofColor> color;

		void assets();

		//importa los elementos desde un archivo JSON
		ofxJSONElement json;

		string nombreTipografia;
		int sizeTipo;

		string archivo;
		bool parsingOk;	
};


