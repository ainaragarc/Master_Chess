#pragma once
#include "propiedades.h"

class Tablero {
	const int TamTablero = 5;
	const float TamCuadrado = 1.0f;
	const float BOARD_OFFSET = -((TamTablero * TamCuadrado) / 2.0f);
	Posicion posicion;

public:

	Posicion get_Pos(int x, int y);
<<<<<<< Updated upstream
	void dibuja();//Desacoplar la parte l�gica de la glut
	void display();
=======
>>>>>>> Stashed changes
	void mouse(int button, int state, int x, int y);
};