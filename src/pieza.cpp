#pragma once
#include "freeglut.h"
#include "pieza.h"
#include "tablero.h"
#include <cmath>

#include <iostream>


void Pieza::mueve(Posicion posicion_final) {	
	posicion = posicion_final;

	if (tipo == Tipo::PEON) { 
		int p;
		(color == Color::BLANCO) ?  p= Tablero::get_numCas() - 1 : p = 0;
		if (posicion.Fila == p) {
			unsigned char tipo;
			std::cout << "c: caballo, t: torre, a: alfil, d: dama";
			do {
				std::cin >> tipo;
			} while (tipo != 'c' && tipo != 't' && tipo != 'a' && tipo != 'd');
			promover(tipo);

			//PROBLEMA, HAY QUE ESTABLECER QUE EL BOT PROMUEVA A ALGO
			//PROBLEMA 2, IMPLEMENTACION IN GAME, NO POR CONSOLA
			//PROBLEMA 3, DEBERIA MOSTRARSE ALGO POR PANTALLA, digo yo
		}
	}
}

 void Pieza::promover(unsigned char& tipo) {
	//para que el peon pueda ejecutar la promocion desde un vector de piezas
	 //No se me ha ocurrido nada mejor
}

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

vector<Posicion> Pieza::posiciones_posibles() {
	auto REY = posiciones_posibles_conrey();
	vector<Posicion> retorno;

	for (const auto& pos : REY) {
		Posicion p = pos;
		if (Tablero::tipo_pieza(p) != Tipo::REY) {
			retorno.push_back(pos);
		}
	}

	return retorno;
}


bool Pieza::estoy_en_tablero(Posicion& pos, int casillas) {
	return (pos.Fila >= 0 && pos.Fila < casillas && pos.Columna >= 0 && pos.Columna < casillas);
}


Tipo Pieza::get_tipo() {return tipo;}
Color Pieza::get_color() {return color;}
int Pieza::get_cantidad() {return cantidad;}
Posicion Pieza::get_posicion_ini() { return posicion;}
