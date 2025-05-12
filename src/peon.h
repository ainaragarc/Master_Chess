#pragma once
#include "pieza.h"

class Peon : public Pieza {
	
public:
	vector<Posicion> posiciones_posibles() override;
	/*void set_posicion_ini(const int f, int c) { posicion.Fila = 1 + f; posicion.Columna = c; };
	void set_fotopiezaB() { foto_pieza = "imagenes/w_pawn_1x_ns.png"; };
	void set_fotopiezaN() { foto_pieza = "imagenes/b_pawn_1x_ns.png"; };
	//se han puesto estas funciones en pucblic para poder acceder correctamente a ellas
	void set_tipo() { tipo = Tipo::PEON; }
	void set_cantidad() { cantidad = 5; }*/

	//prueba inicializacion peon por constructor parametrizado
	Peon(Color equipo, Posicion pos) {
		//esto sustituiria las distintas funciones set
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

	Peon(Posicion pos) { posicion = pos; }
	
};