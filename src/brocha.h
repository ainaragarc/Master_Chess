#pragma once
#include "freeglut.h"
#include "propiedades.h"
#include "Tablero.h"

class Brocha {

	/*static const int numCasillas;
    static const float TamCuadrado;
    static const float BOARD_OFFSET;*/

	static const int longitudVentana = 4;
	Posicion posicion;
public:
	/*int getNumCasillas() const { return numCasillas; }
	float getTamCuadrado() const { return TamCuadrado; }
	float getBoardOffset() const { return BOARD_OFFSET; }*/
	int get_longitudVentana() const { return longitudVentana; }

	void dibuja_t( Tablero& tablero);

	//Función del ratón
	void mouse(int button, int state, int x, int y, const Tablero& tablero, const Brocha& brocha);
	//Funcion que identifica con la glut la posición del tablero
	Posicion get_Pos(int x, int y, const Brocha& brocha, const Tablero& tablero);
	void init_t();
};