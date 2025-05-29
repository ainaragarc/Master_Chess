#pragma once
#include "pieza.h"

class Peon : public Pieza {
	
public:
	vector<Posicion> posiciones_posibles_conrey() override;
	
	Peon(Color equipo, Posicion pos, int nivelBot = 1) {//constructor parametrizado
		cantidad = 5;
		color = equipo;
		posicion = pos;
		tipo = Tipo::PEON;
		if (color == BLANCO) {
			foto_pieza= "imagenes/equipo blanco/ditto.png";
		}
		else {
			foto_pieza = "imagenes/bot1/ditto.png";
		}
		
	}

	
	
};