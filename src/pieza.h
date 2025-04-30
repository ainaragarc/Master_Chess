#pragma once
#include "color.h"

class Pieza {
	float Tamaño;
	char tipo;
	Color color;

public:
	void dibuja();
	void mueve();
	void inicializa();
};