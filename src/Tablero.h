#pragma once
#include "color.h"

class Tablero {
	const int TamTablero = 5;
	const float TamCuadrado = 1.0f;
	const float BOARD_OFFSET = -((TamTablero * TamCuadrado) / 2.0f);
	Color negro = { 0, 0, 0 };
	Color rojo = { 255, 0, 0 };

public:
	void dibuja();
	void display();
	void mouse(int button, int state, int x, int y);
	void init();
};