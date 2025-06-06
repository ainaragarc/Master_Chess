#include "caballo.h"
#include "pieza.h"
#include <vector>
#include "tablero.h"


vector<Posicion> Caballo::posiciones_posibles_conrey() {
	vector<Posicion> posibles;
	Posicion direccion[8] = { {2,1},{2,-1},{1,2},{-1,2},{-2,1},{-2,-1},{1,-2},{-1,-2} };

	for (auto a : direccion) {
		Posicion pos = posicion;
		pos += a;
		
		if (estoy_en_tablero(pos, Tablero::get_numCas())) { posibles.push_back(pos);}
	}

	return posibles;
}

	