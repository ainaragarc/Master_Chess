#pragma once
#include "propiedades.h"
#include <vector>

using std::vector;

enum class Tipo {VACIO=0,  PEON=1, CABALLO, TORRE, ALFIL, REY, REINA };

class Pieza {
protected://Para que las clases derivadas puedan acceder a los atributos
	float Tamano;
	Tipo tipo;//1=Peon,2=caballo,3=torre,4=alfil,5=rey,6=reina 
	int cantidad;//para controlar la cantidad de piezas a inicializar y ver las que hay en el tablero a lo laro de la partida

	// de momento vamos a asignar mejor el color de forma logica con un enum y luego lo pintamos
	Color color;
	Posicion posicion;
	const char* foto_pieza;
	
public:
	virtual vector<Posicion> posiciones_posibles()=0;
	virtual bool movimiento_posible(Posicion posicion_final) ;
	virtual void mueve( Posicion posicion_final);
	
	virtual bool estoy_en_tablero( Posicion& pos, int casillas);

	Posicion& get_posicion() { return posicion; }

	//obtener el tipo de las piezas
	Tipo get_tipo();
	//obtener el color de las piezas
	Color get_color();
	//obtener numero de piezas restantes en juego
	int get_cantidad();

	Posicion get_posicion_ini();

	//prototipo para la gestion del jaque
	virtual bool hay_jaque(const Posicion pos_jaque)const;

	
	friend class Brocha;
	
};