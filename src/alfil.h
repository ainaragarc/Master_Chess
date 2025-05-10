#pragma once
#include "pieza.h"

class Alfil : public Pieza{
	void set_tipo() { tipo = Tipo::ALFIL; }
	void set_cantidad() { cantidad = 1; }


public:
	vector<Posicion> posiciones_posibles() override;
	void set_posicion_ini() { posicion.Fila = 0; posicion.Columna = 0; };

	Alfil(Posicion pos) {posicion = pos;}
	Alfil() = default;

};
