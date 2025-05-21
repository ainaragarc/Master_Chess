#pragma once
#include "Turno.h"
#include "pieza.h"
#include "Mundo.h"

class Mundo;//El compilador necesita saber que existe para poder recibirlo en la función juega (si no da error)

class Bot
{
	bool juega_negras;//variable para controlar con qué piezas juega (futuro)
public:
	void juega(Mundo& mundo); // Método con el que el bot juega
};

