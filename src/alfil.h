#pragma once
#include "pieza.h"

class Alfil : public Pieza{
	void set_tipo() { tipo = Tipo::ALFIL; }
	void set_cantidad() { cantidad = 1; }
	
public:
	vector<Posicion> posiciones_posibles() override;

	Alfil(Posicion pos) {posicion = pos;}
	Alfil() = default;
};
