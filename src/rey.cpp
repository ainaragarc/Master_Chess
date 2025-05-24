#include "rey.h"
#include "pieza.h"
#include <vector>
#include "tablero.h"

 vector<Posicion> Rey::posiciones_posibles_conrey() {
	vector<Posicion> posibles;
	Posicion direccion[8] = { {1,0},{-1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,-1},{-1,1} };

	for (auto a : direccion) {
		Posicion pos = posicion;
		pos += a;

		if (estoy_en_tablero(pos, Tablero::get_numCas())&&!casilla_me_da_jaque(pos)) {
			posibles.push_back(pos); 
		}

	}
		return posibles;
}

bool Rey::casilla_me_da_jaque(Posicion& pos) {
	vector<Pieza*> piezas_enemigas =(color == BLANCO) ? Tablero::get_piezas_N() : Tablero::get_piezas_B();

	for (auto& a : piezas_enemigas) {
		//
		if (a->get_tipo() == Tipo::REY) continue;

		for (auto& b : a->posiciones_posibles()) {
			if (b == pos) {
				return true;
			}
		}
	}

	return false;

}
