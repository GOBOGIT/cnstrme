#include "cajaAnim.h"

cajaAnim::cajaAnim(unsigned int _posFila, int _largo, int _ancho, ofVideoPlayer* _video, ofLoopType _tipoLoop) {
	video = _video;
	largo = _largo;
	h = _ancho;
	tipoLoop = _tipoLoop;
	posFila = _posFila;

	_video->setLoopState(tipoLoop);
	fbo.allocate(largo,h);
}

void cajaAnim::update() {
	video->update();
	fbo.begin();
		ofPushMatrix();
				video->draw(0,0, largo, h);
		ofPopMatrix();
	fbo.end();
}

void cajaAnim::draw() {
	fbo.draw(0,0,largo,h);
}