#pragma once
#include "freeglut.h"
#include "pieza.h"
#include "Posicion.h"

<<<<<<< Updated upstream
void Pieza::dibuja()
=======
/*
void Pieza::dibuja(float radio, int segmentos)
>>>>>>> Stashed changes
{

}
*/

vector<Posicion> Pieza::posiciones_posibles(Pieza& pieza_inical) {
	vector <Posicion> Posiciones_Posibles;
	return Posiciones_Posibles;
}

bool Pieza::mueve(vector<Posicion>& posibles_posiciones, Posicion& posicion_final) {
	return true;
}

/*
Posicion  Pieza::mueve(Pieza& ficha)
{
	//funcion de movimiento
	
	//devuelve la posicion de la ficha que la llama tras moverse
	return ficha.posicion;
}
*/

void Pieza::inicializa()
{

}