#pragma once
#include "pieza.h"

class Torre : public Pieza  {
	

public:
	vector<Posicion> posiciones_posibles_conrey() override;

	Torre(Color equipo, Posicion pos, int nivelBot = 1) {//constructor parametrizado
		cantidad = 1;
		color = equipo;
		posicion = pos;
		tipo = Tipo::TORRE;
		if (color == BLANCO) {
			foto_pieza = "imagenes/equipo blanco/stakataka.png";
		}
		else {
			switch (nivelBot)
			{
			case 1: {foto_pieza = "imagenes/bot1/stakataka.png"; }
				  break;

			case 2: {foto_pieza = "imagenes/bot2/mhtorre.png"; }
				  break;

			case 3: {foto_pieza = "imagenes/bot3/sstorre.png"; }
				  break;

			default:
				break;
			}

		}

	}

	
};