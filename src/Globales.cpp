#include "globales.h"

ofTrueTypeFont Globales::typo = ofTrueTypeFont();
ofTrueTypeFont Globales::typoTitulo = ofTrueTypeFont();
ofTexture Globales::imagenEstaticos = ofTexture();
ofColor Globales::color = ofColor();
ofVideoPlayer Globales::videoAnim = ofVideoPlayer();
 map<string, map<string, ofColor>> Globales::paqueteColores =  map<string, map<string, ofColor>>();


void Globales::assets() {
		typo.loadFont("OCRAStd.otf", 10, true, false, true, 0.1); 
		typoTitulo.loadFont("OCRAStd.otf", 50, true, false, true, 0.1); 
		ofLoadImage(imagenEstaticos, "circuloEstatico.png");
		videoAnim.loadMovie("animPrueba.mov");


		paqueteColores["verde"] ["normal"] = ofColor(195,225,195);
		paqueteColores["verde"] ["click"] = ofColor(150,225,150);
		paqueteColores["verde"] ["disable"] = ofColor(200,200,200);

		paqueteColores["rojo"] ["normal"] = ofColor(225,195,195);
		paqueteColores["rojo"] ["click"] = ofColor(225,150,150);
		paqueteColores["rojo"] ["disable"] = ofColor(200,200,200);
	 
}



ofColor Globales::bgGris() {
	color.r = 250, color.g = 250, color.b = 250;
	return color;
	}


