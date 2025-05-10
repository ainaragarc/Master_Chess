#pragma once
#include "pieza.h"

class Rey : public Pieza {
	void set_tipo() { tipo = Tipo::REY; }
	void set_cantidad() { cantidad = 1; }

public:
	vector<Posicion> posiciones_posibles() override;

	Rey(Posicion pos) { posicion = pos; }
	Rey() = default;
};