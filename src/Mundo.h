#pragma once
#include "Tablero.h"
#include "pieza.h"
#include "brocha.h"
#include "Turno.h"

class Mundo {
private:
	Pieza* pieza_seleccionada = nullptr;
	std::vector<Posicion> casillas_posibles;
	bool esperando_segundo_click = false;
	
	//establecemos el turno inicial para las blancas
	Turno turno_actual = Turno::BLANCO;

public:
	void dibuja();
	void mueve();
	void inicializa_tablero_gardner();
	void inicializa_tablero_baby();

	void gestionar_click(int button, int state, int x, int y);

	Tablero TABLERO;
	
	Brocha BROCHA;
};