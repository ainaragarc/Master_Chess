#pragma once
#include "pieza.h"

class Rey : public Pieza {
	void set_tipo() { tipo = Tipo::REY; }
	void set_cantidad() { cantidad = 1; }

public:
	vector<Posicion> posiciones_posibles() override;
	void set_posicion_ini() { posicion.Fila = 0; posicion.Columna = 4; };
	void set_fotopiezaB() { foto_pieza = "imagenes/w_king_1x_ns.png"; };
	void set_fotopiezaN() { foto_pieza = "imagenes/b_king_1x_ns.png"; };

	Rey(Posicion pos) { posicion = pos; }
	Rey() = default;
};