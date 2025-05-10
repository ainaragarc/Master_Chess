#pragma once
#include "pieza.h"

class Rey : public Pieza {
	void set_tipo() { tipo = Tipo::REY; }
	void set_cantidad() { cantidad = 1; }

public:
	vector<Posicion> posiciones_posibles() override;

	Rey(Posicion pos) { posicion = pos; }
	Rey() = default;
	void set_posicion_ini() { posicion.Fila = 0; posicion.Columna = 4; };
};