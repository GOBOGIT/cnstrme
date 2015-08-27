#include "globales.h"

	
// tipografias
ofTrueTypeFont Globales::typo;

ofTrueTypeFont Globales::typoTitulo = ofTrueTypeFont();

// imagenes
ofTexture Globales::imagenEstaticos = ofTexture();
ofTexture Globales::mockupImagen160x160= ofTexture();
ofTexture Globales::mockupImagen1000x500= ofTexture();
ofImage Globales::imagenUV = ofImage();
// color
ofColor Globales::color = ofColor();
map<string, map<string, ofColor>> Globales::paqueteColores =  map<string, map<string, ofColor>>();

// videos
ofVideoPlayer Globales::videoAnim = ofVideoPlayer();


void Globales::assets() {

		typo.loadFont("OpenSans-Regular.ttf", 12, true, false, false, 0.5); 
		typoTitulo.loadFont("OpenSans-Light.ttf", 60, true, false, false, 0.5); 
		ofLoadImage(imagenEstaticos, "circuloEstatico.png");
		ofLoadImage(mockupImagen160x160, "cajaImg160x160.png");
		ofLoadImage(mockupImagen1000x500, "cajaImg1000x500.png");
		ofLoadImage(imagenUV,"uvtemplate.jpg");
		videoAnim.loadMovie("animPrueba.mov");

		// paquete de colores para botones
		paqueteColores["verde"] ["normal"] = ofColor(195,225,195);
		paqueteColores["verde"] ["click"] = ofColor(150,225,150);
		paqueteColores["verde"] ["disable"] = ofColor(200,200,200);

		paqueteColores["rojo"] ["normal"] = ofColor(225,195,195);
		paqueteColores["rojo"] ["click"] = ofColor(225,150,150);
		paqueteColores["rojo"] ["disable"] = ofColor(200,200,200);
	 
}



ofColor Globales::bgGris() {
	color.r = 200, color.g = 200, color.b = 200;
	return color;
	}

ofColor Globales::bgGrisOscuro() {
	color.r = 220, color.g = 220, color.b = 220;
	return color;
	}


