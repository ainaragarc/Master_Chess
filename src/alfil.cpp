#pragma once
#include "alfil.h"
#include "pieza.h"
#include <vector>
#include "tablero.h"
#include <iostream>

vector<Posicion> Alfil::posiciones_posibles() {
	vector<Posicion> posibles;	
	Posicion direccion[4] = { {1,1},{1,-1},{-1,-1},{-1,1} };
	
	for (auto a :direccion) {
		Posicion pos = posicion;
		//ESTA POSICION SE IRA MOVIENDO A LO LARGO DE LA DIAGONAL, Y RESETEARA PARA LA SIGUIENTE
		for (int i = 0; i < Tablero::get_numCas(); i++) {
			pos += a;
			if (!estoy_en_tablero(pos, Tablero::get_numCas()) || Tablero::tipo_pieza(pos)==Tipo::REY) { break; }
			posibles.push_back(pos);
			if (Tablero::hay_pieza(pos)) { break; }// Salir si hay una pieza en esa posicion PERO DESPUES DE GUARDADRLA
		}
	}
	for (auto& i : posibles) {
		std::cout << "posible: " << i.Fila << ":" << i.Columna << std::endl;
	}
	return posibles;
}