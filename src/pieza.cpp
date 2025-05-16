#pragma once
#include "freeglut.h"
#include "pieza.h"
#include "tablero.h"
#include <cmath>


void Pieza::mueve(Posicion posicion_final) {
	posicion = posicion_final;
}

bool Pieza::movimiento_posible(Posicion posicion_final) {
	//for de rango para comprobar que este entre las posiciones posibles
	auto posibles = posiciones_posibles();
	for (auto& pos : posibles) {
		if (pos.Columna == posicion_final.Columna && pos.Fila == posicion_final.Fila) {
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

//programar funcion
bool Pieza::hay_jaque(Posicion& pos)const {
	//asumo que la pieza que me llega NO es el rey, se reescribira la funcion para si soy el rey, saber si alguien me da jaque
	//paso 1, busco al rey del color contrario

	const vector<Pieza*>& piezas_contrarias = (color == Color::BLANCO) ? Tablero::get_piezas_N() : Tablero::get_piezas_B();
	
	
	for (Pieza* p : piezas_contrarias) {
		if (p->get_tipo() == Tipo::REY) { 
			auto pos_rey_contrario=p->get_posicion();
			break;
			//si la pieza que me llega es la misma que la del rey contrario, no puede serbr
		}
	}
	//compruebo para la posicion si doy jaque al rey con el rey
	return false;
}
