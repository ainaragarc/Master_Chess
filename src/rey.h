#pragma once
#include "pieza.h"

class Torre : public Pieza {
	void set_tipo() { tipo = static_cast<int>(Tipo::REY); }
};