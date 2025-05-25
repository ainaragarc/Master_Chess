#pragma once
#include "pieza.h"

class Peon : public Pieza {
	
public:
	vector<Posicion> posiciones_posibles_conrey() override;
	void mueve(Posicion posicion_final)override;

	void promover(unsigned char&) ;
	
	Peon(Color equipo, Posicion pos) {//constructor parametrizado
		cantidad = 5;
		color = equipo;
		posicion = pos;
		tipo = Tipo::PEON;
		if (color == BLANCO) {
			foto_pieza= "imagenes/w_pawn_1x_ns.png";
		}
		else {
			foto_pieza = "imagenes/b_pawn_1x_ns.png";
		}
		
	}

	
	
};