#include "globales.h"

// tipografias
map<string,ofTrueTypeFont> Globales:: tipografia;

// mapa de imagenes
map<string,ofImage>  Globales::iconos;
map<string,ofImage>  Globales::imagenes;

// color
map<string,ofColor>  Globales::color;
map<string, map<string, ofColor>> Globales::paqueteColores;

// videos
map<string, ofVideoPlayer> Globales::videoPlayer;


void Globales::assets(){
		

		// carga el archivo de importacion de elementos audiovisuales
		archivo ="JSON/multimedia.json";
		parsingOk = json.open(archivo);
		if (parsingOk) 
			ofLogNotice("ofApp::setup") << json.getRawString(); 
	    else 
	        ofLogError("ofApp::setup")  << "Failed to parse JSON" << endl; 

		
		for(ofxJSONElement js : json["tipo"])
			tipografia[js["name"].asString()].loadFont(js["file"].asString(),  js["size"].asInt(), true, false, false, 0.5); 

		for(ofxJSONElement js : json["ico"])
			iconos[js["name"].asString()].loadImage(js["file"].asString());

		for(ofxJSONElement js : json["img"])
			imagenes[js["name"].asString()].loadImage(js["file"].asString());
		

		for(ofxJSONElement js : json["vid"]) 
			videoPlayer[js["name"].asString()].loadMovie(js["file"].asString());


		for(ofxJSONElement js : json["color"])
			color[js["name"].asString()] = ofColor(js["r"].asInt(),js["g"].asInt(),js["b"].asInt());

		for(ofxJSONElement js : json["rgb"]){
			for(ofxJSONElement jsc : js["color"])
				paqueteColores[js["grupo"].asString()][jsc["is"].asString()] = ofColor(
					jsc["r"].asInt(),
					jsc["g"].asInt(),
					jsc["b"].asInt());
		} 


}

