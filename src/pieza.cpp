#pragma once
#include "freeglut.h"
#include "pieza.h"
#include <cmath>


bool Pieza::mueve(Posicion posicion_final) {
	//for de rango para comprobara que este entre las posiciones posibles
	auto posibles=posiciones_posibles();
	for (auto& pos : posibles) {
		if (pos.Columna == posicion_final.Columna && pos.Fila == posicion_final.Fila) {
			posicion = posicion_final;
			return true;
			//si cumple la condicion, se mueve la pieza, y bool=1
		}
	}
	return false;
}

bool Pieza::estoy_en_tablero(Posicion& pos, int casillas) {
	return (pos.Fila >= 0 && pos.Fila < casillas && pos.Columna >= 0 && pos.Columna < casillas);
}


Tipo Pieza::get_tipo() {return tipo;}
Color Pieza::get_color() {return color;}
int Pieza::get_cantidad() {return cantidad;}
Posicion Pieza::get_posicion_ini() { return posicion;}