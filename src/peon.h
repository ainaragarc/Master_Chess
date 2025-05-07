#pragma once
#include "pieza.h"

class Peon : public Pieza {
	void set_tipo() { tipo = static_cast<int>(Tipo::PEON); }
	
};