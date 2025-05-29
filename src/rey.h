#pragma once
#include "pieza.h"

class Rey : public Pieza {

public:
	vector<Posicion> posiciones_posibles_conrey() override;

	Rey(Color equipo, Posicion pos) {//constructor parametrizado
		cantidad = 1;
		color = equipo;
		posicion = pos;
		tipo = Tipo::REY;
		if (color == BLANCO) {
			foto_pieza = "imagenes/equipo blanco/ash.png";
		}
		else {
			foto_pieza = "imagenes/bot1/giovanni.png";
		}

	}
	bool casilla_me_da_jaque(Posicion & pos);

};