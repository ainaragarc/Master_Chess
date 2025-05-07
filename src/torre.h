#pragma once
#include "pieza.h"

class Torre : public Pieza  {
	void set_tipo()  { tipo = Tipo::TORRE; }
};