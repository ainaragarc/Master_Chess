#pragma once
#include "Tablero.h"
#include "pieza.h"
#include "brocha.h"
#include "Turno.h"
#include "Bot.h"


class GestorEstados;//le digo a mundo que existe la clase para no incluir la clase entera (gestorestados contiene a mundo y haria bucle)

class Mundo {
private:
	Pieza* pieza_seleccionada = nullptr;

	std::vector<Posicion> casillas_posibles;
	bool esperando_segundo_click = false;
	GestorEstados* estado = nullptr;//puntero gestor estados desde mundo para controlar los estados 
	
	//establecemos el turno inicial para las blancas
	Turno turno_actual = Turno::BLANCO;
	
public:
	void dibuja();
	void mueve();
	void inicializa_tablero_gardner();
	void inicializa_tablero_baby();

	void gestionar_click(int button, int state, int x, int y);

	//funcion para cambiar el estado del juego durante la partida
	void set_estado(GestorEstados* g) { estado = g; }

	Turno get_turno() const{ return turno_actual; }
	void cambiar_turno_bot();
	void cambiar_turno_prueba() {
		turno_actual = (turno_actual == Turno::BLANCO) ? Turno::NEGRO : Turno::BLANCO;
	}

	//FUNCION PARA PODER RECOGER CARACTER DE GESTOR DE ESTADOS
	void seleccionar_coronacion(unsigned char tipo);


	Tablero TABLERO;
	Brocha BROCHA;
};