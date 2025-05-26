#pragma once
#include "pieza.h"

class Caballo : public Pieza {
	

public:
	vector<Posicion> posiciones_posibles_conrey() override;

	Caballo(Color equipo, Posicion pos) {//constructor parametrizado
		cantidad = 1;
		color = equipo;
		posicion = pos;
		tipo = Tipo::CABALLO;
		if (color == BLANCO) {
			foto_pieza = "imagenes/ponyta.png";
		}
		else {
			foto_pieza = "imagenes/b_knight_1x_ns.png";
		}

	}

	
};