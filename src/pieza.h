#pragma once
#include "color.h"

class Pieza {
	float Tama�o;
	char tipo;
	Color color;

public:
	void dibuja();
	void mueve();
	void inicializa();
};