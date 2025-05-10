#pragma once
#include "propiedades.h"
#include "brocha.h"
#include <vector>
#include "pieza.h"

using namespace std;

class Tablero {
	int numCasillas = 5;
    float TamCuadrado = 1;
	Posicion posicion;

	//cantidad de piezas, entidad que nos ayudará a inicializarlas y controlarlas
	vector<Pieza*> piezas_B;
	vector<Pieza*> piezas_N;

public:
	//Metodos para que las funciones de dibujo puedan acceder a los atributos por medio de la variable TABLERO creada en Mundo
	int get_numCas() { return numCasillas; }
	float get_TamCuad() { return TamCuadrado; }
	int& get_fila() { return posicion.Fila; }
	int& get_columna() { return posicion.Columna; }

	const std::vector<Pieza*>& get_piezas_B() const { return piezas_B; }

	void inicializa_piezas();
	//funciones para limpiar mas el codigo de inicializa pieza
	void añadir_piezas_B(vector<Pieza*>& equipo, Pieza* pieza);
	void añadir_piezas_N(vector<Pieza*>& equipo, Pieza* pieza);
	
	friend class Brocha;
};