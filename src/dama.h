#pragma once
#include "pieza.h"

class Dama : public Pieza {
	

public:
	vector<Posicion> posiciones_posibles() override;
	/*void set_posicion_ini(const int f, int c) { posicion.Fila = 0 + f; posicion.Columna = 3 + c; };
	void set_fotopiezaB() { foto_pieza = "imagenes/w_queen_1x_ns.png"; };
	void set_fotopiezaN() { foto_pieza = "imagenes/b_queen_1x_ns.png"; };
	//se han puesto estas funciones en pucblic para poder acceder correctamente a ellas
	void set_tipo() { tipo = Tipo::REINA; }
	void set_cantidad() { cantidad = 1; }*/

	Dama(Color equipo, Posicion pos) {
		//esto sustituiria las distintas funciones set
		cantidad = 5;
		color = equipo;
		posicion = pos;
		tipo = Tipo::REINA;
		if (color == BLANCO) {
			foto_pieza = "imagenes/w_queen_1x_ns.png";
		}
		else {
			foto_pieza = "imagenes/b_queen_1x_ns.png";
		}

	}



	
};