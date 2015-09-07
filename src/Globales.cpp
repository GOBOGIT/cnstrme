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
ofVideoPlayer Globales::videoAnim;


void Globales::assets() {

		tipografia["med"].loadFont("OpenSans-Regular.ttf", 12, true, false, false, 0.5); 
		tipografia["titulo"].loadFont("OpenSans-Light.ttf", 60, true, false, false, 0.5); 

		iconos["iconoInicio"].loadImage("Iconos/inicio.png");
		iconos["icoGaleria"].loadImage("Iconos/icoGaleria.png");

		iconos["cerrar400x50"].loadImage("Iconos/cerrar400x50.png");

		imagenes["mockup160x160"].loadImage("cajaImg160x160.png");
		imagenes["mockup1000x500"].loadImage("cajaImg1000x500.png");

		videoAnim.loadMovie("animPrueba.mov");

		paqueteColores["verde"] ["normal"] = ofColor(195,225,195);
		paqueteColores["verde"] ["click"] = ofColor(150,225,150);
		paqueteColores["verde"] ["disable"] = ofColor(200,200,200);

		paqueteColores["rojo"] ["normal"] = ofColor(225,195,195);
		paqueteColores["rojo"] ["click"] = ofColor(225,150,150);
		paqueteColores["rojo"] ["disable"] = ofColor(200,200,200);
	 

		color["gris200"] = ofColor(200);
		color["gris220"] = ofColor(220);
}