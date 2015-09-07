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
	 float anchoTotalVentana;
	 ofFbo ventana;
	 vector<Contenedor> contenedores;
	 void reset();
	 void dibujaLimites();



	// p: pressed
    bool p;
	// id: boton del raton, por defecto 0;
    int pID;
	// posicion inicial del mouse en Y
    float pOrigin;
    float desOrigin;
	float time;
	float position;
    float destination;
    float velocity;

public:

	Grid() {
		contenedorID =0;
		posxContenedor = 0;
		posyFila = 0;
		ofRegisterMouseEvents(this);	
		p=false;
		pOrigin=0;
		desOrigin=0;
		time = ofGetElapsedTimef();
		reset();

	};

	~Grid() {};

	void mouseMoved(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
	void mousePressed(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);

	
	void draw(int,int,int,int);
	void update();
	void add(vector<Contenedor>);
	bool dentro(float,float);
	
	void estados(bool);
	

	

	
	
};