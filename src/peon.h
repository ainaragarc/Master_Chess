#pragma once
#include "pieza.h"

class Peon : public Pieza {
	void set_tipo() { tipo = Tipo::PEON; }
	void set_cantidad() { cantidad = 5; }

public:
	vector<Posicion> posiciones_posibles() override;

	Peon(Posicion pos) { posicion = pos; }
	Peon() = default;
};