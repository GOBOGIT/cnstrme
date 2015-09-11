#include "Grid.h"


#define DAMPING 10.
#define MASS 1.
#define K 30.

void Grid::setup() {

}

void Grid::draw(int _posx, int _posy, int _largoVentana, int _anchoventana) {


	posy = _posy;
	largoVentana = _largoVentana;
	anchoVentana = _anchoventana;


	ventana.allocate(largoVentana,anchoVentana, GL_RGBA);
	// numero de contenedores
	numContenedores = contenedores.size();
	// numero elementos en cada fila ( cuando todos los contenedores tienen el mismo largo
	numCol = floor(largoVentana / (contenedores[0].largo+5));
	// numero de filas necesarioas
	numFilas = ceil(numContenedores / numCol);
	// ancho total del contenido
	anchoTotalVentana =(numFilas * contenedores[0].anchoFinal) + posy;

	//centra el grid
	posx = (_largoVentana/2) - ((numCol * contenedores[0].largo + 5)/2);

	ventana.begin();
	
	ofPushMatrix();
		for(unsigned int i = 0; i < numFilas; i++) {
			for(unsigned int ii = 0; ii < numCol; ii++) {
				if(contenedorID < numContenedores) {	
					
					contenedores[contenedorID].draw(posxContenedor,posyFila+position);
					contenedores[contenedorID].update(posx, posy);
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
	
	ventana.end();

	ventana.draw(ofRectangle(posx,posy,largoVentana,anchoVentana));
	//dibujaLimites();

	float t=ofGetElapsedTimef();
    float dt=t-time;
    time=t;
        
    float accel=destination-position;
    accel*=(K/MASS);
    accel-=(DAMPING/MASS)*velocity;
    velocity+=(accel*dt);
    position+=(velocity*dt);


}

void Grid::add(vector<Contenedor> _contenedor) {
	contenedores.swap(_contenedor);
}


void Grid::mouseMoved(ofMouseEventArgs & args){}
void Grid::mouseDragged(ofMouseEventArgs & args){

	if(dentro(args.x, args.y)) {
		if(p)
			destination = desOrigin + (args.y - pOrigin);
		}
}

void Grid::mousePressed(ofMouseEventArgs & args){
	if(dentro(args.x, args.y)) {
		p=true;
		pOrigin=args.y;
		desOrigin=destination;
	}
}
void Grid::mouseReleased(ofMouseEventArgs & args){
 if(p){
        destination = desOrigin + (args.y - pOrigin);
		if(anchoTotalVentana<anchoVentana){
            destination = 0;
        }
        else if(destination>0){
            destination = 0;
        }
		else if(destination< (anchoVentana-anchoTotalVentana)){
			destination = (anchoVentana-anchoTotalVentana);
        }
        p = false;
    }
}	


bool Grid::dentro(float _x, float _y) {
		return ((_x > posx) && (_x < largoVentana) && (_y > posy) && (_y < anchoVentana));
}

void Grid::dibujaLimites() {
/*
		int posLinea;
	
		if(dragy == 0 || dragy <= -(anchoTotalVentana-anchoVentana)){
			if(dragy == 0)
				posLinea = posy;
			else
				posLinea = anchoVentana+posy - 5;

		ofPushStyle();
			ofFill;
			ofSetColor(ofColor::orangeRed);
			ofRect((ofGetViewportWidth()/2)-100,posLinea,200,5);
		ofPopStyle();
	} */
}


void Grid::update() {


}

void Grid::estados(bool _estado) {
		
	

	if(_estado) {
		ofRegisterMouseEvents(this);
		for(unsigned int i=0; i < contenedores.size(); i++) {
			contenedores[i].estados(true);
		}
	}else
	{
		reset();
		ofUnregisterMouseEvents(this);
	}

}


void Grid::reset(){
	position=0;
    destination=0;
    velocity=0;
}