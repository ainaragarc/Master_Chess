#pragma once
#include "Tablero.h"
#include "pieza.h"
#include "brocha.h"

class Mundo {
private:
	Pieza* pieza_seleccionada = nullptr;
	std::vector<Posicion> casillas_posibles;
	bool esperando_segundo_click = false;

public:
	void dibuja();
	void mueve();
	void inicializa();

	void gestionar_click(int button, int state, int x, int y);

	Tablero TABLERO;
	
	Brocha BROCHA;
};