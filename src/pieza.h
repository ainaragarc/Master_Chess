#pragma once
#include "color.h"
#include "Posicion.h"

//Enum class para los tipos de pieza, posible uso con switch case en mundo/tablero para dibujar, mover
enum class Tipo { PEON, CABALLO, TORRE, ALFIL, REY, REINA };

class Pieza {
	float Tama�o;
	int cantidad;
	
	Color color;
	Posicion posicion;
	Tipo tipo;
	

public:
	void dibuja();

	//propuesta de devolver una posici�n al mover una ficha, esta har� una cosa u otra dependiendo de qu� tipo es.l
	Posicion mueve(Pieza& ficha);
	void inicializa();
	
};