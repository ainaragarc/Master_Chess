#pragma once
#include "propiedades.h"
#include <vector>
using std::vector;

enum class Tipo { PEON=1, CABALLO, TORRE, ALFIL, REY, REINA };

//enum culum { A = 1, B, C, D, E };

class Pieza {
protected://Para que las clases derivadas puedan acceder a los atributos
	float Tamano;
	Tipo tipo;//1=Peon,2=caballo,3=torre,4=alfil,5=rey,6=reina 
	int cantidad;//para controlar la cantidad de piezas a inicializar y ver las que hay en el tablero a lo laro de la partida

	// de momento vamos a asignar mejor el color de forma logica con un enum y luego lo pintamos
	Color color;
	Posicion posicion;
	const char* foto_pieza;
	//Tipo tipo;
	
public:
	//void dibuja(float radio, int segmentos);

	//propuesta de devolver una posici�n al mover una ficha, esta har� una cosa u otra dependiendo de qu� tipo es.l
	virtual vector<Posicion> posiciones_posibles(Pieza& pieza_inical);
	//saca las posiciones posibles para la pieza seleccionada, devuelve el vector de posiciones posibles

	virtual bool mueve(vector<Posicion>& posibles_posiciones, Posicion& posicion_final);
	//mueve comprueba que se puede mover (devolviendo false si no se puede), y realiza el movimiento
	//Hay que mioodificar�la�memoria

	virtual void set_tipo(){}//POR DEFECTO NO HACE  NADA Y PERMITE QUE LAS DEMAS SUBCLASES LA SOBREESCRIBAN

	virtual void set_cantidad() {}//tendremos una cantidad distinta de cada pieza

	virtual void set_posicion_ini() {};//Para definir la posici�n inicial de cada pieza

	virtual void set_fotopieza() {};
	//asigna el color de blanco o negro a las piezas
	void set_color(Color asignaci�n_color) { color = asignaci�n_color; };

	//posicion inicial de las piezas
	void set_posicion(Posicion posicion);



	//obtener el tipo de las piezas
	Tipo get_tipo();

	//obtener el color de las piezas
	Color get_color();

	//obtener numero de piezas restantes en juego
	int get_cantidad();

	Posicion get_posicion_ini();

	void inicializa();
	
	friend class Brocha;
	
};