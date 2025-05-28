#pragma once
#include "Turno.h"
#include "pieza.h"
#include "Mundo.h"

class Mundo;//El compilador necesita saber que existe para poder recibirlo en la funci�n juega (si no da error)

class Bot
{
	bool juega_negras = 1;//variable para controlar con qu� piezas juega (futuro)
	int medalla_amarilla{};
	int medalla_fuego{};
	int medalla_azul{};
public:
	void juegaNivel1(Mundo& mundo); // M�todo con el que el bot juega
	void juegaNivel2(Mundo& mundo); // M�todo con el que el bot juega
	void juegaNivel3(Mundo& mundo); // M�todo con el que el bot juega
};

