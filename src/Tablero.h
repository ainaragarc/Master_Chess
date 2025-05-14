#pragma once
#include "propiedades.h"
#include "brocha.h"
#include <vector>
#include "pieza.h"

using std::vector;
using std::cout;
using std::endl;

class Tablero {
	static const int numCasillas = 5;
    float TamCuadrado = 1;
	Posicion posicion;

	//cantidad de piezas, entidad que nos ayudará a inicializarlas y controlarlas
	static vector<Pieza*> piezas_B;
	static vector<Pieza*> piezas_N;

public:
	//Metodos para que las funciones de dibujo puedan acceder a los atributos por medio de la variable TABLERO creada en Mundo
	static int get_numCas() { return numCasillas; }
	float get_TamCuad() { return TamCuadrado; }
	int& get_fila() { return posicion.Fila; }
	int& get_columna() { return posicion.Columna; }

	static bool hay_pieza(Posicion& pos);
	static bool hay_pieza_BLANCA(Posicion& pos);
	static bool hay_pieza_NEGRA(Posicion& pos);
	static Tipo tipo_pieza(Posicion& pos);

	const vector<Pieza*>& get_piezas_B() const { return piezas_B; }
	const vector<Pieza*>& get_piezas_N() const { return piezas_N; }

	void inicializa_piezas();
	//funciones para limpiar mas el codigo de inicializa pieza
	void anadir_piezas_B(vector<Pieza*>& equipo, Pieza* pieza);
	void anadir_piezas_N(vector<Pieza*>& equipo, Pieza* pieza);
	
	friend class Brocha;


	//funciones de prueba
	void PRUEBADEMOVIMIENTO();
	void Pruebapiezas();
};