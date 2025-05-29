#pragma once
#include "pieza.h"

class Dama : public Pieza {
	

public:
	vector<Posicion> posiciones_posibles_conrey() override;

	Dama(Color equipo, Posicion pos, int nivelBot = 1) {//constructor parametrizado
		cantidad = 1;
		color = equipo;
		posicion = pos;
		tipo = Tipo::REINA;
		if (color == BLANCO) {
			foto_pieza = "imagenes/equipo blanco/gardevoir.png";
		}
		else {
			switch (nivelBot)
			{
			case 1: {foto_pieza = "imagenes/bot1/gardevoir.png"; }
				  break;

			case 2: {foto_pieza = "imagenes/bot2/mhdama.png"; }
				  break;

			case 3: {foto_pieza = "imagenes/bot3/ssdama.png"; }
				  break;

			default:
				break;
			}

		}

	}
	
};