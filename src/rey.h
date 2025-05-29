#pragma once
#include "pieza.h"

class Rey : public Pieza {

public:
	vector<Posicion> posiciones_posibles_conrey() override;

	Rey(Color equipo, Posicion pos, int nivelBot = 1) {//constructor parametrizado
		cantidad = 1;
		color = equipo;
		posicion = pos;
		tipo = Tipo::REY;
		if (color == BLANCO) {
			foto_pieza = "imagenes/equipo blanco/ash.png";
		}
		else {
			switch (nivelBot)
			{
			case 1: {foto_pieza = "imagenes/bot1/giovanni.png"; }
				  break;

			case 2: {foto_pieza = "imagenes/bot2/MH_rey.png"; }
				  break;

			case 3: {foto_pieza = "imagenes/bot3/SS_rey.png"; }
				  break;

			default:
				break;
			}
		}

	}
	bool casilla_me_da_jaque(Posicion & pos);

};