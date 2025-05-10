#pragma once
#include "pieza.h"

class Alfil : public Pieza{
	void set_tipo() { tipo = Tipo::ALFIL; }
	void set_cantidad() { cantidad = 1; }
	void set_posicion_ini() { posicion.Fila = 0; posicion.Columna = 0; };
};