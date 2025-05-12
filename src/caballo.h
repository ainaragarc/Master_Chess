#pragma once
#include "pieza.h"

class Caballo : public Pieza {
	

public:
	vector<Posicion> posiciones_posibles() override;
	void set_posicion_ini(const int f, int c) { posicion.Fila = 0 + f; posicion.Columna = 1 + c; };
	void set_fotopiezaB() { foto_pieza = "imagenes/w_knight_1x_ns.png"; };
	void set_fotopiezaN() { foto_pieza = "imagenes/b_knight_1x_ns.png"; };
	void set_tipo() { tipo = Tipo::CABALLO; }
	void set_cantidad() { cantidad = 1; }

	Caballo(Posicion pos) { posicion = pos; }
	Caballo() = default;
};