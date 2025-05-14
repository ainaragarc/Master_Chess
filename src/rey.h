#pragma once
#include "pieza.h"

class Rey : public Pieza {
	

public:
	vector<Posicion> posiciones_posibles() override;
	
	Rey(Color equipo, Posicion pos) {//constructor parametrizado
		cantidad = 1;
		color = equipo;
		posicion = pos;
		tipo = Tipo::REY;
		if (color == BLANCO) {
			foto_pieza = "imagenes/w_king_1x_ns.png";
		}
		else {
			foto_pieza = "imagenes/b_king_1x.png";
		}

	}

	
};