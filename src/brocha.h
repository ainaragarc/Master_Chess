#pragma once
#include "freeglut.h"
#include "propiedades.h"
#include <iostream>

class Brocha {

public:
	void dibuja_t(int numCasillas, float TamCuadrado);
	void init_t(float longitudVentana);

	Posicion get_Pos(int x, int y, float longitudVentana, float TamCuadrado, int numCasillas,int& fila, int& columna);
	void mouse(int button, int state, int x, int y, float longitudVentana, float TamCuadrado, int numCasillas, int& fila, int& columna);
};