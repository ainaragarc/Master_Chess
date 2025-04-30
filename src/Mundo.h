#pragma once
#include "Tablero.h"
#include "pieza.h"

class Mundo {
	int x_ojo;
	int y_ojo;
	int z_ojo;
public:
	void dibuja();
	void mueve();
	void inicializa();

	Tablero TABLERO;
	Pieza PIEZA;
};