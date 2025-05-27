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
			foto_pieza = "imagenes/Ash.png";
		}
		else {
			foto_pieza = "imagenes/b_king_1x.png";
		}

	}
	bool casilla_me_da_jaque(Posicion & pos);

};