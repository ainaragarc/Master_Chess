#pragma once
#include "propiedades.h"
#include "brocha.h";
#include <vector>
#include "pieza.h"

using namespace std;

class Tablero {
	Posicion posicion;
	//cantidad de piezas, entidad que nos ayudar� a inicializarlas y controlarlas
	vector<Pieza*> piezas_B;
	vector<Pieza*> piezas_N;

public:
	void inicializa_piezas();
	Posicion get_Pos(int x, int y, const Brocha& brocha);
	void mouse(int button, int state, int x, int y, const Brocha& brocha);
};