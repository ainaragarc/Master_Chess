#pragma once
#include "pieza.h"

class Peon : public Pieza {
	
public:
	vector<Posicion> posiciones_posibles_conrey() override;
	
	Peon(Color equipo, Posicion pos) {//constructor parametrizado
		cantidad = 5;
		color = equipo;
		posicion = pos;
		tipo = Tipo::PEON;
		if (color == BLANCO) {
			foto_pieza= "imagenes/equipo blanco/ditto.png";
		}
		else {
			foto_pieza = "imagenes/b_pawn_1x_ns.png";
		}
		
	}

	
	
};