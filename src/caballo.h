#pragma once
#include "pieza.h"

class Caballo : public Pieza {
	void set_tipo() { tipo = static_cast<int>(Tipo::CABALLO); }
};