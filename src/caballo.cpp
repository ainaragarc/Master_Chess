#include "caballo.h"


vector<Posicion> Caballo::posiciones_posibles() {
	vector<Posicion> posibles;

<<<<<<< Updated upstream
=======
	for (auto a : direccion) {
		Posicion pos = get_posicion();
		pos += a;
		if (estoy_en_tablero(pos, Tablero::get_numCas())) {
			posibles.push_back(pos);
		}

		//COMO SE PUEDE COMER A TODAS LAS PIEZAS PODRA IR A TODAS LAS POSCIONES, SALVO SI ES UN REY!!!
		//IMPLEMENTAR EL REY
	}
>>>>>>> Stashed changes
	return posibles;
}