#pragma once
#include "pieza.h"

class Torre : public Pieza  {
	

public:
	vector<Posicion> posiciones_posibles_conrey() override;

	Torre(Color equipo, Posicion pos) {//constructor parametrizado
		cantidad = 1;
		color = equipo;
		posicion = pos;
		tipo = Tipo::TORRE;
		if (color == BLANCO) {
			foto_pieza = "imagenes/w_rook_1x_ns.png";
		}
		else {
			foto_pieza = "imagenes/b_rook_1x_ns.png";
		}

	}

	
};