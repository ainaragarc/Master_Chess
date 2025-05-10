#pragma once
#include "pieza.h"

class Peon : public Pieza {
	void set_tipo() { tipo = Tipo::PEON; }
	void set_cantidad() { cantidad = 5; }

public:
	vector<Posicion> posiciones_posibles() override;

	Peon(Posicion pos) { posicion = pos; }
	Peon() = default;
	void set_posicion_ini() { posicion.Fila = 0; posicion.Columna = 3; };
};