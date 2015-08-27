#pragma once
#include "ofMain.h"
#include "Contenedor.h"
#include "ofxTween.h"

class Grid {

	 float numCol;
	 float numFilas;
	 int largo, ancho;
	 int numContenedores;
	 int posxContenedor, posyFila;
	 int contenedorID;
	 int posx,posy, largoVentana, anchoVentana;
	 float dragy;
	 float anchoTotalVentana;
	 int posyMouse;
	 bool pressed;
	 bool anim;

public:

	Grid() {
		contenedorID =0;
		posxContenedor = 0;
		posyFila = 0;
		dragy=0;
		pressed = true;
		anim = true;
		ofRegisterMouseEvents(this);	
	};

	~Grid() { cout << "destruye Grid" << endl; };

	void mouseMoved(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
	void mousePressed(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);

	
	void draw(int,int,int,int);
	void update();
	void add(vector<Contenedor>);
	bool dentro(float,float);
	void dibujaLimites();
	void estados(bool);

	ofxTween tween;
	ofxEasingLinear easinglinear;

	vector<Contenedor> contenedores;
	ofFbo ventana;
	
};