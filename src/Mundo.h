#pragma once
#include "Tablero.h"
#include "pieza.h"
#include "brocha.h"

class Mundo {
public:
	void dibuja();
	void mueve();
	void inicializa();

	Tablero TABLERO;
	Pieza PIEZA;
	Brocha BROCHA;
};