#include "Peon.h"
#include "pieza.h"
#include <vector>
#include "tablero.h"

vector<Posicion> Peon::posiciones_posibles() {
	vector<Posicion> posibles;
	Posicion pos = get_posicion();

	Posicion direccion = {1,0};
	Posicion diagonales[2] = { {1,1}, {1,-1} };
	int fila_inicial = 1;

	//cambio de direcciones si es ficha negra
	if (Tablero::hay_pieza_NEGRA(pos)) { 
		direccion.Fila = -direccion.Fila;
		for (auto & a : diagonales) { a.Fila = -a.Fila; }
		fila_inicial = 3;
	}

	pos += direccion; // Avanzar 1
	//comprueba si esta dentro del tablero
	if (estoy_en_tablero(pos, Tablero::get_numCas())) {
		posibles.push_back(pos);
		if (!(Tablero::hay_pieza(pos) && get_posicion().Fila == fila_inicial)){
			//si no hay pieza en la posicion y es la fila inicial, puede avanzar 2
			pos += direccion;
			if (estoy_en_tablero(pos, Tablero::get_numCas())){
				posibles.push_back(pos);
			}
			
		}
	}

//comprobar si puede comer en diagonal
	for (auto a : diagonales) {
		pos = get_posicion();
		pos += a;
		if (estoy_en_tablero(pos, Tablero::get_numCas())&& Tablero::hay_pieza(pos)) {
			posibles.push_back(pos);; // Salir del bucle si se sale del tablero
		}
	}
	
		//COMO SE PUEDE COMER A TODAS LAS PIEZAS PODRA IR A TODAS LAS POSCIONES, SALVO SI ES UN REY!!!
		//IMPLEMENTAR EL REY
	return posibles;
}