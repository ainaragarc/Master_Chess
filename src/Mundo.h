#pragma once
#include "Tablero.h"
#include "pieza.h"
#include "brocha.h"

class Mundo {
	int x_ojo = 0;
	int y_ojo = 0;
	int z_ojo = 10;
public:
	void dibuja();
	void mueve();
	void inicializa();

	Tablero TABLERO;
	Pieza PIEZA;
	Brocha BROCHA;
};