#pragma once
#include "alfil.h"
#include "pieza.h"
#include <vector>
#include "tablero.h"

vector<Posicion> Alfil::posiciones_posibles() {
	vector<Posicion> posibles;	
	// quiero que recorra las diagonales

	Posicion direccion[4] = { {1,1},{1,-1},{-1,-1},{-1,1} };

	for (auto a :direccion) {
		
		for (int i = 1; i < Tablero::get_numCas(); i++) {
			posicion.Fila += a.Fila;
			posicion.Columna += a.Columna;
			if (posicion.Fila < 0 || posicion.Fila >= Tablero::get_numCas() || posicion.Columna < 0 || posicion.Columna >= Tablero::get_numCas()) {
				break; // Salir si se sale del tablero
			}
			posibles.push_back(pos);
			if (Tablero::hay_pieza(pos)) { break; }// Salir si hay una pieza en esa posicion PERO DESPUES DE GUARDADRLA
		}
	}

	return posibles;
}