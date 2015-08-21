#include "Grid.h"

Grid::Grid() {
	contenedorID =0;
	posxContenedor = 0;
	posyFila = 0;

}


void Grid::draw(int _posx, int _posy, int _largoVentana, int _anchoventana) {

	
	posy = _posy;
	largoVentana = _largoVentana;
	anchoVentana = _anchoventana;

	// numero de contenedores
	numContenedores = contenedores.size();
	// numero elementos en cada fila ( cuando todos los contenedores tienen el mismo largo
	numCol = floor(largoVentana / (contenedores[0].largo+5));
	// numero de filas necesarioas
	numFilas = ceil(numContenedores / numCol);
	

	//centra el grid
	posx = (_largoVentana/2) - ((numCol * contenedores[0].largo + 5)/2);


	ofPushMatrix();
		ofTranslate(posx, posy);
		for(unsigned int i = 0; i < numFilas; i++) {
			for(unsigned int ii = 0; ii < numCol; ii++) {
				if(contenedorID < numContenedores) {	
					contenedores[contenedorID].estados(true);
					contenedores[contenedorID].textoTitulo = to_string(contenedorID);
					contenedores[contenedorID].draw(posxContenedor,posyFila);
					posxContenedor += contenedores[contenedorID].largo+5;
			
				++contenedorID;
				} 
			
			}
			posxContenedor = 0;
			posyFila += contenedores[i].anchoFinal+5;
		}
		contenedorID = 0;
		posyFila = 0;
	ofPopMatrix();
	
}

void Grid::add(vector<Contenedor> _contenedor) {
	contenedores.swap(_contenedor);
}

