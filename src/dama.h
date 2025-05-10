#pragma once
#include "pieza.h"

class Dama : public Pieza {
	void set_tipo() { tipo = Tipo::REINA; }
	void set_cantidad() { cantidad = 1; }

public:
	vector<Posicion> posiciones_posibles() override;
	void set_posicion_ini() { posicion.Fila = 0; posicion.Columna = 2; };
	void set_fotopieza() { foto_pieza = "imagenes/w_queen_1x_ns.png"; };

	Dama(Posicion pos) { posicion = pos; }
	Dama() = default;
};