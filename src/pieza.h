#pragma once
<<<<<<< Updated upstream
#include "color.h"
#include "Posicion.h"
=======
#include "propiedades.h"
#include <vector>

using std::vector;
>>>>>>> Stashed changes

//Enum class para los tipos de pieza, posible uso con switch case en mundo/tablero para dibujar, mover
enum class Tipo { PEON, CABALLO, TORRE, ALFIL, REY, REINA };

class Pieza {
	float Tamaño;
	int cantidad;
	
	Color color;
	Posicion posicion;
	Tipo tipo;
	

public:
<<<<<<< Updated upstream
	void dibuja();
=======
	// ESTO SE TIENE QUE IR A BROCHA
	// void dibuja(float radio, int segmentos);
>>>>>>> Stashed changes

	//propuesta de devolver una posición al mover una ficha, esta hará una cosa u otra dependiendo de qué tipo es.l
	
	virtual vector<Posicion> posiciones_posibles(Pieza& pieza_inical);
	//saca las posiciones posibles para la pieza seleccionada, devuelve el vector de posiciones posibles

	virtual bool mueve(vector<Posicion> & posibles_posiciones, Posicion& posicion_final);
	//mueve comprueba que se puede mover (devolvienod false si no se puede), y realiza el movimiento
	//Hay que mioodificar la memoria

	void inicializa();
	
};