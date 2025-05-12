#pragma once
#include "pieza.h"

class Alfil : public Pieza{
	void set_tipo() { tipo = Tipo::ALFIL; }
	void set_cantidad() { cantidad = 1; }


public:
	vector<Posicion> posiciones_posibles() override;
	void set_posicion_ini() { posicion.Fila = 0; posicion.Columna = 0; };
	void set_fotopiezaB() { foto_pieza = "imagenes/w_bishop_1x_ns.png"; };
	void set_fotopiezaN() { foto_pieza = "imagenes/b_bishop_1x_ns.png"; };


	Alfil(Posicion pos) {posicion = pos;}
	Alfil() = default;

};
