#pragma once
#include "freeglut.h"
#include "propiedades.h"

class Brocha {

public:
	void dibuja_t(int numCasillas, float TamCuadrado);
	void init_t(float longitudVentana);

	//Posicion get_Pos(int x, int y, const Brocha& brocha);
	//void mouse(int button, int state, int x, int y, const Brocha& brocha);
};