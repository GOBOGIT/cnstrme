#pragma once
#include "ofMain.h"


class Eventos {



public:

	Eventos();
	~Eventos() {cout << "destruye Eventos" << endl;}

	void mouseMoved(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
	void mousePressed(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);
};