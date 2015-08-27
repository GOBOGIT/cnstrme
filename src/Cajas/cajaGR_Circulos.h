#pragma once
#include "ofMain.h"
#include "ofxTween.h"
#include "../Globales.h"

class cajaGrCirculos {


	ofxTween anim;
	ofxEasingBounce easingBounce;
	ofPath path, circulo;

	int w;
	float vMax, vFinal;
	float porcentajeFinal;
	float valorTween;
	float escalaCirculo;
	float escalaInterior;
	int resolucion;
	int radio;
	bool iniciar;
	ofColor bg,fg;
	ofTrueTypeFont valores;

public:

	cajaGrCirculos() {};

	/** parametros
	@param posicion de arriba a abajo en el contenedor
	@param largo y ancho para fbo.allocate
	@param Valor maximo del arco (coincide con los 360 grados)
	@param valor que se desea mostrar 
	@param escalaCirculo relativo a la caja (0.8 por defecto)
	@param escalaCirculo interior relativo a la caja (0.9 por defecto)
	@param color de fondo (white por defecto)
	@param color de la barra (ligthGray por defecto)
	 */
	cajaGrCirculos(
		unsigned int _posFila, 
		int _w,
		int _h, 
		float _vMax, 
		float _vFinal, 
		float _escalaCirculo = 0.8, 
		float _escalaInterior = 0.9, 
		ofColor = ofColor::white, 
		ofColor  = ofColor::lightGray);
	
	~cajaGrCirculos(){};

	void draw();
	void iniciaAnim();
	void update();

	ofFbo fbo;
	int h;
	unsigned int posFila;


};