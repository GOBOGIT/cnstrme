#pragma once
#include "ofMain.h"
#include "ofxTween.h"
#include "Globales.h"

#include "Gui\Contenedor.h"
#include "Cajas\cajaImagen.h"
#include "Cajas\\cajaTexto.h"


class Rafaga {

	float posyRafaga;
	float duracion;
	float velocidad;
	ofColor color;
	bool finalizar;
	bool terminado;

public:


	Rafaga() {};
	/** prametros
	@param duracion
	@param velocidad animacion  (defecto 500)
	@param color de fondo		(defecto lightGray) */
	Rafaga(float, float = 500, ofColor = ofColor::lightGray);
	~Rafaga(){};

	void draw();
	void update();
	void estado(bool);
	bool getter();
	bool iniciar;

	ofxTween anim;
	ofxTween animSalida;
	ofxEasingQuint	EasingSine;


	Contenedor contenedor;
	cajaImagen cajaImg;
	cajaTexto cajaTxt;
};