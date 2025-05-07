#pragma once
#include "pieza.h"

class Alfil : public Pieza{
	void set_tipo() { tipo = static_cast<int>(Tipo::ALFIL); }
	
};