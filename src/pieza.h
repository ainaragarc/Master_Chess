#pragma once
#include "color.h"
#include "Posicion.h"

//Enum class para los tipos de pieza, posible uso con switch case en mundo/tablero para dibujar, mover
enum class Tipo { PEON, CABALLO, TORRE, ALFIL, REY, REINA };

class Pieza {
	float Tamaño;
	int cantidad;
	
	Color color;
	Posicion posicion;
	Tipo tipo;
	

public:
	void dibuja();

	//propuesta de devolver una posición al mover una ficha, esta hará una cosa u otra dependiendo de qué tipo es.l
	Posicion mueve(Pieza& ficha);
	void inicializa();
	
};