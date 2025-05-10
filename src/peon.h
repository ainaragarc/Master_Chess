#pragma once
#include "pieza.h"

class Peon : public Pieza {
	void set_tipo() { tipo = Tipo::PEON; }
	void set_cantidad() { cantidad = 5; }
	void set_posicion_ini() {};
};