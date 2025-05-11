#pragma once
#include "alfil.h"
#include "pieza.h"
#include <vector>
#include "tablero.h"
#include <iostream>

vector<Posicion> Alfil::posiciones_posibles() {
	vector<Posicion> posibles;	
	// quiero que recorra las diagonales desde donde este, hasta que toque final de tablero o una pieza

	Posicion direccion[4] = { {1,1},{1,-1},{-1,-1},{-1,1} };
	
	for (auto a :direccion) {
		Posicion pos = get_posicion();
		//ESTA POSICION SE IRA MOVIENDO A LO LARGO DE LA DIAGONAL, Y RESETEARA PARA LA SIGUIENTE
		for (int i = 0; i < Tablero::get_numCas(); i++) {
			pos += a;
			if (!estoy_en_tablero(pos, Tablero::get_numCas())) {
				break; // Salir del bucle si se sale del tablero
			}
			posibles.push_back(pos);
			if (Tablero::hay_pieza(pos)) { break; }// Salir si hay una pieza en esa posicion PERO DESPUES DE GUARDADRLA
			//COMO SE PUEDE COMER A TODAS LAS PIEZAS PODRA IR A TODAS LAS POSCIONES, SALVO SI ES UN REY!!!
			//IMPLEMENTAR EL REY
		}
	}
	for (auto& i : posibles) {
		std::cout << "posible: " << i.Columna << ":" << i.Fila << std::endl;
	}
	return posibles;
}