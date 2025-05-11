#include "caballo.h"

#include "pieza.h"
#include <vector>
#include "tablero.h"


vector<Posicion> Caballo::posiciones_posibles() {
	vector<Posicion> posibles;
	Posicion direccion[8] = { {2,1},{2,-1},{1,2},{-1,2},{-2,1},{-2,-1},{1,-2},{-1,-2} };

	for (auto a : direccion) {
		Posicion pos = get_posicion();
		pos += a;
		if (estoy_en_tablero(pos, Tablero::get_numCas())) {
			posibles.push_back(pos);
		}

		//COMO SE PUEDE COMER A TODAS LAS PIEZAS PODRA IR A TODAS LAS POSCIONES, SALVO SI ES UN REY!!!
		//IMPLEMENTAR EL REY
	}
	return posibles;
}