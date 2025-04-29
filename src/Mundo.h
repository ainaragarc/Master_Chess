#pragma once
#include "Tablero.h"

class Mundo {
	int x_ojo;
	int y_ojo;
	int z_ojo;
public:
	void dibuja();
	void mueve();
	void inicializa();
	void tecla(unsigned char key);
	void tecla_especial(unsigned char key);

	Tablero TABLERO;
};