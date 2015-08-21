#pragma once
#include "ofMain.h"
#include "Contenedor.h"

class Grid {

	 float numCol;
	 float numFilas;
	 int largo, ancho;
	 int numContenedores;
	 int posxContenedor, posyFila;
	 int contenedorID;
	 int posx,posy, largoVentana, anchoVentana;
	

public:

	Grid();
	~Grid() { cout << "destruye Grid" << endl; };

	vector<Contenedor> contenedores;
	void draw(int,int,int,int);
	void update();
	void add(vector<Contenedor>);

	
};