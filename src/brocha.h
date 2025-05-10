#pragma once
#include "freeglut.h"
#include "propiedades.h"
#include <iostream>
#include <ETSIDI.h>

class Brocha {
	float longitudVentana = 4;
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
	void mouse(int button, int state, int x, int y, float longitudVentana, float TamCuadrado, int numCasillas, int& fila, int& columna);
	
	void dibuja_ini(float TamCuadrado, int numCasillas, int fila, int columna);
};