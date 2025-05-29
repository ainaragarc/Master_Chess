#pragma once
#include "Turno.h"
#include "pieza.h"
#include "Mundo.h"
#include "PantallaMedallas.h"

class Mundo;//El compilador necesita saber que existe para poder recibirlo en la función juega (si no da error)

class Bot
{
	bool juega_negras = 1;//variable para controlar con qué piezas juega (futuro)
	//Atributos para dar medallas por ganar nivel
	static bool medalla_amarilla;//Victoria nivel 1
	static bool medalla_fuego;//Victoria nivel 2
	static bool medalla_azul;//Victoria nivel 3

public:
	void juegaNivel1(Mundo& mundo); // Método con el que el bot juega
	void juegaNivel2(Mundo& mundo); // Método con el que el bot juega
	void juegaNivel3(Mundo& mundo); // Método con el que el bot juega
	void set_medalla_amarilla() { medalla_amarilla = true; }

	/*bool tiene_medalla(std::string medalla) {
		if (medalla == "amarilla")return medalla_amarilla;
	}*/
	static void otorgar_medalla_amarilla() { medalla_amarilla = true; }
	static bool tiene_medalla_amarilla() { return medalla_amarilla; }

	static void otorgar_medalla_fuego() { medalla_fuego = true; }
	static bool tiene_medalla_fuego() { return medalla_fuego; }

	static void otorgar_medalla_azul() { medalla_azul = true; }
	static bool tiene_medalla_azul() { return medalla_azul; }
};