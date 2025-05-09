#pragma once
#include "pieza.h"

class Rey : public Pieza {
	void set_tipo() { tipo = Tipo::REY; }
	void set_cantidad() { cantidad = 1; }
	
};