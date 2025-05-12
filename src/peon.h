#pragma once
#include "pieza.h"

class Peon : public Pieza {
	void set_tipo() { tipo = Tipo::PEON; }
	void set_cantidad() { cantidad = 5; }

public:
	vector<Posicion> posiciones_posibles() override;
	void set_posicion_ini(const int f, int c) { posicion.Fila = 1 + f; posicion.Columna = 0 + c; };
	void set_fotopiezaB() { foto_pieza = "imagenes/w_pawn_1x_ns.png"; };
	void set_fotopiezaN() { foto_pieza = "imagenes/b_pawn_1x_ns.png"; };

	Peon(Posicion pos) { posicion = pos; }
	Peon() = default;
};