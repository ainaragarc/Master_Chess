#pragma once
#include "freeglut.h"
#include "pieza.h"
#include "Posicion.h"

void Pieza::dibuja()
{

}

Posicion  Pieza::mueve(Pieza& ficha)
{
	//funcion de movimiento
	
	//devuelve la posicion de la ficha que la llama tras moverse
	return ficha.posicion;
}

void Pieza::inicializa()
{

}