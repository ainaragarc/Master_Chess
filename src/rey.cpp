#include "rey.h"
#include "pieza.h"
#include <vector>
#include "tablero.h"

vector<Posicion> Rey::posiciones_posibles() {
	vector<Posicion> posibles;
	Posicion direccion[8] = { {1,0},{-1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,-1},{-1,1} };

	for (auto a : direccion) {
		Posicion pos = posicion;
		pos += a;
		if (estoy_en_tablero(pos, Tablero::get_numCas()) && Tablero::tipo_pieza(pos) != Tipo::REY) { posibles.push_back(pos); }

	}
		return posibles;
}