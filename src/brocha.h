#pragma once
#include "freeglut.h"

class Brocha {

	static const int numCasillas;
    static const float TamCuadrado;
    static const float BOARD_OFFSET;

	static const int longitudVentana;
public:
	int getNumCasillas() const { return numCasillas; }
	float getTamCuadrado() const { return TamCuadrado; }
	float getBoardOffset() const { return BOARD_OFFSET; }
	int get_longitudVentana() const { return longitudVentana; }

	void dibuja_t();
	void init_t();
};