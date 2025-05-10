#pragma once
#include "pieza.h"

class Dama : public Pieza {
	void set_tipo() { tipo = Tipo::REINA; }
	void set_cantidad() { cantidad = 1; }

public:
	vector<Posicion> posiciones_posibles() override;

	Dama(Posicion pos) { posicion = pos; }
	Dama() = default;
};