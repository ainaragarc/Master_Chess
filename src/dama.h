#pragma once
#include "pieza.h"

class Dama : public Pieza {
	void set_tipo() { tipo = static_cast<int>(Tipo::REINA); }
};