#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"


class gestor3D {


	ofFloatColor color;
	ofxAssimpModelLoader escena;
	ofLight light;

public:


	void setup();
	void update();
	void draw();

	void setter(string, bool);

	ofEasyCam camara;
	string seleccion;

	// para acceder directamente a metodos de assimp y no de openframeworks
	const struct aiScene* esceAssimp;
	void collectNodes(const struct aiScene *sc, const struct aiNode *nd);
};