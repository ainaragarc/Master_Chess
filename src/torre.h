#pragma once
#include "pieza.h"

class Torre : public Pieza  {
	void set_tipo()  { tipo = Tipo::TORRE; }
	void set_cantidad() { cantidad = 1; }

public:
	vector<Posicion> posiciones_posibles() override;
	void set_posicion_ini(const int f, int c) { posicion.Fila = 0 + f; posicion.Columna = 0 + c; };
	void set_fotopiezaB() { foto_pieza = "imagenes/w_rook_1x_ns.png"; };
	void set_fotopiezaN() { foto_pieza = "imagenes/b_rook_1x_ns.png"; };


	Torre (Posicion pos) { posicion = pos;}
	Torre() = default;
};