#include "rey.h"
#include "pieza.h"
#include <vector>
#include "tablero.h"


vector<Posicion> Rey::posiciones_posibles() {
	vector<Posicion> posibles;
	Posicion direccion[8] = { {1,0},{-1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,-1},{-1,1} };

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