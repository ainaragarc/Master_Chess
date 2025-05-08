#pragma once
#include "propiedades.h"
#include "brocha.h"
#include <vector>
#include "pieza.h"

using namespace std;

class Tablero {
	Posicion posicion;
	//cantidad de piezas, entidad que nos ayudará a inicializarlas y controlarlas
	vector<Pieza*> piezas_B;
	vector<Pieza*> piezas_N;
	int numCasillas;
	float TamCuadrado;
	float BOARD_OFFSET;
public:
	Tablero();
	void inicializa_piezas();
	int getnumCasillas() const { return numCasillas; }
	float getTamCuadrado() const { return TamCuadrado; }
	float getBOARD_OFFSET() const { return BOARD_OFFSET; }
	/*Posicion get_Pos(int x, int y, const Brocha& brocha);*/
	//void mouse(int button, int state, int x, int y, const Brocha& brocha);
	friend class Brocha;
};