#pragma once
#include "pieza.h"

class Peon : public Pieza {
	void set_tipo() { tipo = Tipo::PEON; }
	void set_cantidad() { cantidad = 5; }

public:
	vector<Posicion> posiciones_posibles() override;
	void set_posicion_ini() { posicion.Fila = 0; posicion.Columna = 3; };
	void set_fotopiezaB() { foto_pieza = "imagenes/w_pawn_1x_ns.png"; };
	void set_fotopiezaN() { foto_pieza = "imagenes/b_pawn_1x_ns.png"; };

	Peon(Posicion pos) { posicion = pos; }
	Peon() = default;
};