#include "dama.h"
#include "pieza.h"
#include <vector>
#include "tablero.h"

vector<Posicion> Dama::posiciones_posibles() {
	vector<Posicion> posibles;
	Posicion direccion[8] = { {1,0},{-1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,-1},{-1,1} };

	for (auto a : direccion) {
		Posicion pos = get_posicion();
		for (int i = 0; i < Tablero::get_numCas(); i++) {
			pos += a;
			if (!estoy_en_tablero(pos, Tablero::get_numCas())) {
				break;
			}
			posibles.push_back(pos);
			if (Tablero::hay_pieza(pos)) { break; }// Salir si hay una pieza en esa posicion PERO DESPUES DE GUARDADRLA
			//COMO SE PUEDE COMER A TODAS LAS PIEZAS PODRA IR A TODAS LAS POSCIONES, SALVO SI ES UN REY!!!
			//IMPLEMENTAR EL REY
		}
	}
	return posibles;
}