#pragma once
#include "freeglut.h"
#include "pieza.h"
#include <cmath>

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
}

void Pieza::inicializa()
{

}
