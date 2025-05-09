#pragma once
#include "pieza.h"

class Torre : public Pieza  {
	void set_tipo()  { tipo = Tipo::TORRE; }
	void set_cantidad() { cantidad = 1; }
};