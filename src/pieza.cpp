#pragma once
#include "freeglut.h"
#include "pieza.h"
#include "Posicion.h"
#include <cmath>

void Pieza::dibuja(float radio, int segmentos)
{
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP); // Usa GL_POLYGON para un círculo sólido
    for (int i = 0; i < segmentos; i++) {
        float theta = 2.0f * 3.1415926f * i / segmentos;
        float x = radio * cos(theta);
        float y = radio * sin(theta);
        glVertex2f(x, y);
    }
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
