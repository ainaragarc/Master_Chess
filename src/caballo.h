#pragma once
#include "pieza.h"

class Caballo : public Pieza {
	

public:
	vector<Posicion> posiciones_posibles_conrey() override;

	Caballo(Color equipo, Posicion pos, int nivelBot = 1) {//constructor parametrizado
		cantidad = 1;
		color = equipo;
		posicion = pos;
		tipo = Tipo::CABALLO;
		if (color == BLANCO) {
			foto_pieza = "imagenes/equipo blanco/rapidash.png";
		}
		else {
			switch (nivelBot)
			{
			case 1: {foto_pieza = "imagenes/bot1/rapidash.png"; }
				  break;

			case 2: {foto_pieza = "imagenes/bot2/mhcaballo.png"; }
				  break;

			case 3: {foto_pieza = "imagenes/bot3/sscaballo.png"; }
				  break;

			default:
				break;
			}

		}

	}

	
};