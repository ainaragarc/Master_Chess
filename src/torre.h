#pragma once
#include "pieza.h"

class Torre : public Pieza  {
	void set_tipo()  { tipo = Tipo::TORRE; }
	void set_cantidad() { cantidad = 1; }

public:
	vector<Posicion> posiciones_posibles() override;

	Torre (Posicion pos) { posicion = pos;}
	Torre() = default;
	void set_posicion_ini() { posicion.Fila = 0; posicion.Columna = 5; };
};