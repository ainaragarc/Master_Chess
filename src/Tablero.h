#pragma once
#include "propiedades.h"
#include "brocha.h";

class Tablero {
	Posicion posicion;

public:

	Posicion get_Pos(int x, int y, const Brocha& brocha);
	void mouse(int button, int state, int x, int y, const Brocha& brocha);
};