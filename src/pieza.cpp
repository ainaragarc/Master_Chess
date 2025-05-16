#pragma once
#include "freeglut.h"
#include "pieza.h"
#include "tablero.h"
#include <cmath>


void Pieza::mueve(Posicion posicion_final) {	posicion = posicion_final;	}

bool Pieza::movimiento_posible(Posicion posicion_final) {
	//for de rango para comprobar que este entre las posiciones posibles
	auto posibles = posiciones_posibles();
	for (auto& pos : posibles) {
		if (pos == posicion_final && Tablero::tipo_pieza(pos) != Tipo::REY) {
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

vector<Posicion> Pieza::posiciones_posibles_jaque(){
	vector<Posicion> pos_jaque;
	/*
	Posicion pos_rey_contrario= (color == Color::BLANCO) ? Tablero::pos_Rey(NEGRO) : Tablero::pos_Rey(BLANCO);

	//paso 2, busco las posiciones posibles que dan jaque al rey contrario
	for (auto a : posiciones_posibles()) {
		for (auto& b : a.posiciones_posibles()) {
			if (b == pos_rey_contrario) { pos_jaque.push_back(a); }
		}
	}
	*/
	return pos_jaque;
}
