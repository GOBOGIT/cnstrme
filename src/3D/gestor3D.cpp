#include "gestor3D.h"


void gestor3D::setup(){
	
	//??
	ofDisableArbTex();

	escena.loadModel("instancias2.dae",false);
	escena.enableColors();
	escena.enableMaterials();

	// controles propios de assimp
	esceAssimp = escena.getAssimpScene();

	//posicion inicial de la camara
	camara.setPosition(ofPoint(ofGetWidth()/2, ofGetHeight()/2, 700));

	// inicializa seleccion
	seleccion = "";

	//ajusta colores  GLOBALES en la escena
	 GLfloat global_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };  
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);  
    GLfloat specular[] = {0.2f, 0.2f, 0.2f, 1.0f};  
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);  
    GLfloat diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};  
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);  
    GLfloat ambient[] = {0.2, 0.2f, 0.2f, 0.2f};  
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);  
    GLfloat position[] = { 0.5f, 0.5f, 0.5f, 1.0f};  
    glLightfv(GL_LIGHT0, GL_POSITION, position);  

   

	 
}


void gestor3D::collectNodes(const struct aiScene *sc, const struct aiNode *nd) {

		
		int index =0;
		for(unsigned i = 0; i < nd -> mNumChildren; ++i) {
			// captura el nombre del NODO del mesh	
			string nombre =  nd-> mChildren[i] -> mName.data;
			cout << seleccion << endl;
			if(nombre == seleccion){
				
				// recupera la información del nodo seleccionado
					ofxAssimpMeshHelper &meshHelper = escena.getMeshHelper(index);
					// crea un material y se hace una copia en çel del material del objeto
					ofMaterial & material = meshHelper.material;
					// se modifica la copia del material.
					material.setAmbientColor(color);
			}
	
		index++;
	}
}

void gestor3D::draw(){
	glEnable(GL_DEPTH_TEST); 
	glEnable(GL_LIGHTING); 
	glEnable(GL_LIGHT0);
	glDisable(GL_COLOR_MATERIAL);
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
 	//ofEnableDepthTest();
	//light.enable();
	//ofEnableSeparateSpecularLight();  
	
		camara.begin();
			ofPushMatrix();
				//http://www.openframeworks.cc/documentation/ofxAssimpModelLoader/ofxAssimpModelLoader.html
				escena.drawFaces();
			ofPopMatrix();
		camara.end();
	
	glDisable(GL_LIGHT0);  
	glDisable(GL_LIGHTING); 
	glDisable(GL_DEPTH_TEST); 

	//light.disable();
  //  ofDisableLighting();
	//ofDisableDepthTest();

}

void gestor3D::update(){
	escena.update();
	
	// llama al metodo que se mueve enter los elementos de la escena 3D
	collectNodes(esceAssimp, esceAssimp->mRootNode);

}

void gestor3D::setter(string _sel, bool _cambioColor){
		seleccion = _sel;
			
		if(_cambioColor) 
			color = ofFloatColor(0.0,1.0,0.0,0);
		else
			color = ofFloatColor(0.0,0.0,0.0,0);
}