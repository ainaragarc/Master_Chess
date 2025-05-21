#pragma once
#include "Tablero.h"
#include "pieza.h"
#include "brocha.h"
#include "Turno.h"
#include "Bot.h"

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

	Turno get_turno() const{ return turno_actual; }
	void cambiar_turno_bot() { turno_actual = cambiar_turno(turno_actual); }
	void cambiar_turno_prueba() {
		turno_actual = (turno_actual == Turno::BLANCO) ? Turno::NEGRO : Turno::BLANCO;
	}

	Tablero TABLERO;
	Brocha BROCHA;
};