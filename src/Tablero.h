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
	static Posicion pos_Rey(Color col);

	static bool Jaque(Color col);
	bool es_jaque_mate(Color color);
	bool es_ahogado(Color color);
	Pieza* comer_pieza(Posicion pos);
	Pieza* get_pieza_en_pos(const Posicion& pos);

	static  vector<Pieza*>& get_piezas_B() { return piezas_B; }
	static  vector<Pieza*>& get_piezas_N() { return piezas_N; }

	void inicializa_piezas_GARDNER();
	void inicializa_piezas_BABY();
	//funciones para limpiar mas el codigo de inicializa pieza
	void anadir_piezas_B(vector<Pieza*>& equipo, Pieza* pieza);
	void anadir_piezas_N(vector<Pieza*>& equipo, Pieza* pieza);
	
	friend class Brocha;
	friend void keyboard(unsigned char key, int x, int y);

	static void coronar(Pieza* p, unsigned char& tipo);
	//funciones de prueba
	void Pruebapiezas();


};