#include "cajaAnim.h"

cajaAnim::cajaAnim(int _largo, int _ancho, ofVideoPlayer _video) {
	video = _video;
	largo = _largo;
	ancho = _ancho;

	video.setLoopState(OF_LOOP_NONE);
	fbo.allocate(largo,ancho);

}

void cajaAnim::update() {
	
	video.update();
	fbo.begin();
		ofPushMatrix();
					video.draw(0,0, largo, ancho);
		ofPopMatrix();
	fbo.end();
}

void cajaAnim::draw() {
	//video.play();
	fbo.draw(0,0,largo,ancho);
}