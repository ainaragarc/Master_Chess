#pragma once
#include "freeglut.h"
#include "pieza.h"
#include <cmath>

/*
void Pieza::dibuja(float radio, int segmentos)
{
    glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere(radio, segmentos, 10);
    glEnd();
}

Posicion  Pieza::mueve(Pieza& ficha)
{
	//funcion de movimiento
	
	//devuelve la posicion de la ficha que la llama tras moverse
	return ficha.posicion;
}*/


bool Pieza::mueve(Posicion& posicion_final) {
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

void Pieza::inicializa() {
	
}

Tipo Pieza::get_tipo() {
	return tipo;
}

Color Pieza::get_color() {
	return color;
}

int Pieza::get_cantidad() {
	return cantidad;
}




