#pragma once
#include "freeglut.h"
#include "propiedades.h"
#include <iostream>
#include <ETSIDI.h>
#include <vector>
#include "pieza.h"

class Brocha {
	float longitudVentana = 4;
	Pieza* pieza_seleccionada = nullptr;
	bool es_blanca_seleccionada = false;//Puede servirnos a la hora de comer piezas
public:
	//Metodo para acceder a la variable longitudVentana por medio del objeto BROCHA
	float get_longVent() { return longitudVentana; }

	//Funcion que dibuja el tablero
	void dibuja_t(int numCasillas, float TamCuadrado);

	//Funcion que inicializa la ventana del juego
	void init_t(float longitudVentana);

	//Funcion "interfaz" que convierte las coordenadas de la pantalla a OpenGL y posteriormente a las casillas del tablero
	Posicion get_Pos(int x, int y, float longitudVentana, float TamCuadrado, int numCasillas,int& fila, int& columna);

	//Funcion de control del ratón
	void mouse(int button, int state, int x, int y, float longitudVentana, float TamCuadrado, int numCasillas, int& fila, int& columna,
		 const std::vector<Pieza*>& blancas,const std::vector<Pieza*>& negras);

	//Funcion que dibuja el tablero de inicio
	void dibuja_ini(float TamCuadrado, int numCasillas, const std::vector<Pieza*>& equipo);

	
	//primero prototipo de movimiento(en deshuso)
	Posicion click_a_posicion(int button, int state, int x, int y, float longitudVentana, float TamCuadrado, int numCasillas);

	//funcion que resalta las posibles casillas de movimiento de las piezas
	void resalta_casillas(const std::vector<Posicion>& posiciones, float TamCuadrado, int numCasillas);
};