#pragma once
#include "pieza.h"

class Alfil : public Pieza{
	

public:
	vector<Posicion> posiciones_posibles_conrey() override;
	
	Alfil(Color equipo, Posicion pos) {//constructor parametrizado
		cantidad = 1;
		color = equipo;
		posicion = pos;
		tipo = Tipo::ALFIL;
		if (color == BLANCO) {
			foto_pieza = "imagenes/w_bishop_1x_ns.png";
		}
		else {
			foto_pieza = "imagenes/b_bishop_1x_ns.png";
		}

	}


	
};
