#pragma once
#include "propiedades.h"
#include <vector>
using std::vector;

enum class Tipo { PEON, CABALLO, TORRE, ALFIL, REY, REINA };
enum color {BLANCO, NEGRO};
//enum culum { A = 1, B, C, D, E };

class Pieza {
protected://Para que las clases derivadas puedan acceder a los atributos
	float Tamano;
	int tipo;//1=Peon,2=caballo,3=torre,4=alfil,5=rey,6=reina 

	Color color;
	Posicion posicion;
	//Tipo tipo;
	
public:
	//void dibuja(float radio, int segmentos);

	//propuesta de devolver una posición al mover una ficha, esta hará una cosa u otra dependiendo de qué tipo es.l
	virtual vector<Posicion> posiciones_posibles(Pieza& pieza_inical);
	//saca las posiciones posibles para la pieza seleccionada, devuelve el vector de posiciones posibles

	virtual bool mueve(vector<Posicion>& posibles_posiciones, Posicion& posicion_final);
	//mueve comprueba que se puede mover (devolvienod false si no se puede), y realiza el movimiento
	//Hay que mioodificar la memoria

	virtual void set_tipo(){}//POR DEFECTO NO HACE  NADA Y PERMITE QUE LAS DEMAS SUBCLASES LA SOBREESCRIBAN
	virtual void inicializa(){}
	
	
};