#pragma once
#include "propiedades.h"
#include "brocha.h";
#include <vector>
#include "pieza.h"

using namespace std;

class Tablero {
	int numCasillas = 5;
    float TamCuadrado = 1;
	float longitudVentana = 4;

	Posicion posicion;
	//cantidad de piezas, entidad que nos ayudará a inicializarlas y controlarlas
	vector<Pieza*> piezas_B;
	vector<Pieza*> piezas_N;

public:
	int get_numCas() { return numCasillas; }
	float get_TamCuad() { return TamCuadrado; }
	float get_longVent() { return longitudVentana; }

	void inicializa_piezas();
	//funciones para limpiar mas el codigo de inicializa pieza
	void añadir_piezas_B(vector<Pieza*>& equipo, Pieza* pieza);
	void añadir_piezas_N(vector<Pieza*>& equipo, Pieza* pieza);

	Posicion get_Pos(int x, int y, const Brocha& brocha);
	void mouse(int button, int state, int x, int y, const Brocha& brocha);
};