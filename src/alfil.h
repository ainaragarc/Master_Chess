#pragma once
#include "pieza.h"

class Alfil : public Pieza{
	

public:
	vector<Posicion> posiciones_posibles() override;
	void set_posicion_ini(const int f, int c) { posicion.Fila = 0 + f; posicion.Columna = 2; };
	void set_fotopiezaB() { foto_pieza = "imagenes/w_bishop_1x_ns.png"; };
	void set_fotopiezaN() { foto_pieza = "imagenes/b_bishop_1x_ns.png"; };
	//se han puesto estas funciones en pucblic para poder acceder correctamente a ellas
	void set_tipo() { tipo = Tipo::ALFIL; }
	void set_cantidad() { cantidad = 1; }


	Alfil(Posicion pos) {posicion = pos;}
	Alfil() = default;

};
