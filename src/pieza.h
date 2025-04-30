#pragma once
#include "color.h"

class Pieza {
	float Tamano;
	char tipo;
	Color color;

public:
	void dibuja();
	void mueve();
	void inicializa();
};