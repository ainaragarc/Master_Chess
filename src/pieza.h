#pragma once
#include "propiedades.h"

//Enum class para los tipos de pieza, posible uso con switch case en mundo/tablero para dibujar, mover
//enum class Tipo { PEON, CABALLO, TORRE, ALFIL, REY, REINA };
//enum color {BLANCO = 0, NEGRO = 1};
//enum culum { A = 1, B, C, D, E };

class Pieza {
	float Tamano;
	int cantidad; // No tengo muy claro para que sirve esto (help)

	Color color;
	Posicion posicion;
	//Tipo tipo;
	
public:
	void dibuja(float radio, int segmentos);

	//propuesta de devolver una posición al mover una ficha, esta hará una cosa u otra dependiendo de qué tipo es.l
	Posicion mueve(Pieza& ficha);
	void inicializa();
	
	
};