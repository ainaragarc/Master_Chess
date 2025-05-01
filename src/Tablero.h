#pragma once
#include "propiedades.h"

class Tablero {
	const int TamTablero = 5;
	const float TamCuadrado = 1.0f;
	const float BOARD_OFFSET = -((TamTablero * TamCuadrado) / 2.0f);

public:
	Posicion posicion;

	void dibuja();
	void display();
	void mouse(int button, int state, int x, int y);
	void init();
};