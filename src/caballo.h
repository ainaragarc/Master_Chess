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
			foto_pieza = "imagenes/equipo blanco/rapidash.png";
		}
		else {
			foto_pieza = "imagenes/bot1/rapidash.png";
		}

	}

	
};