#pragma once
#include "pieza.h"

class Dama : public Pieza {
	

public:
	vector<Posicion> posiciones_posibles_conrey() override;

	Dama(Color equipo, Posicion pos) {//constructor parametrizado
		cantidad = 1;
		color = equipo;
		posicion = pos;
		tipo = Tipo::REINA;
		if (color == BLANCO) {
			foto_pieza = "imagenes/Mewtwo.png";
		}
		else {
			foto_pieza = "imagenes/b_queen_1x_ns.png";
		}

	}
	
};