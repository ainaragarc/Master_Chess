#pragma once
#include "alfil.h"
#include "pieza.h"
#include <vector>
#include "tablero.h"

vector<Posicion> Alfil::posiciones_posibles_conrey() {
	vector<Posicion> posibles;	
	Posicion direccion[4] = { {1,1},{1,-1},{-1,-1},{-1,1} };
	
	for (auto a :direccion) {
		Posicion pos = posicion;
		for (int i = 0; i < Tablero::get_numCas(); i++) {
			pos += a;
			if (!estoy_en_tablero(pos, Tablero::get_numCas())) { break; }
			posibles.push_back(pos);
			if (Tablero::hay_pieza(pos)) { break; }// Salir si hay una pieza en esa posicion PERO DESPUES DE GUARDADRLA
		}
	}
	
	return posibles;
}