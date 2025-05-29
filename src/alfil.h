#pragma once
#include "pieza.h"

class Alfil : public Pieza{
	

public:
	vector<Posicion> posiciones_posibles_conrey() override;
	
	Alfil(Color equipo, Posicion pos, int nivelBot = 1) {//constructor parametrizado
		cantidad = 1;
		color = equipo;
		posicion = pos;
		tipo = Tipo::ALFIL;
		if (color == BLANCO) {
			foto_pieza = "imagenes/equipo blanco/bisharp.png";
		}
		else {
			switch (nivelBot)
			{
			case 1: {foto_pieza = "imagenes/bot1/bisharp.png"; }
				  break;

			case 2: {foto_pieza = "imagenes/bot2/mhalfil.png"; }
				  break;

			case 3: {foto_pieza = "imagenes/bot3/ssalfil.png"; }
				  break;

			default:
				break;
			}
			
		}

	}


	
};
