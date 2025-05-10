#pragma once
#include "pieza.h"

class Caballo : public Pieza {
	void set_tipo() { tipo = Tipo::CABALLO; }
	void set_cantidad() { cantidad = 1; }

public:
	vector<Posicion> posiciones_posibles() override;
	void set_posicion_ini() { posicion.Fila = 0; posicion.Columna = 1; };

	Caballo(Posicion pos) { posicion = pos; }
	Caballo() = default;
};