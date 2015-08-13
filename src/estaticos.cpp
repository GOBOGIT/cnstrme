#include "estaticos.h"


ofTrueTypeFont estaticos::typo = ofTrueTypeFont();
ofTexture estaticos::imagenEstaticos = ofTexture();

void estaticos::tipoBtn() {

	cout <<"entra" << endl;
		
	
		typo.loadFont("OCRAStd.otf", 10, true, false, true, 0.1); 
		ofLoadImage(imagenEstaticos, "circuloEstatico.png");
}