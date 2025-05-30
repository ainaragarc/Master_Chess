#include "rey.h"
#include "pieza.h"
#include <vector>
#include "tablero.h"
#include <cmath>

 vector<Posicion> Rey::posiciones_posibles_conrey() {
	vector<Posicion> posibles;
	Posicion direccion[8] = { {1,0},{-1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,-1},{-1,1} };

	for (auto a : direccion) {
		Posicion pos = posicion;
		pos += a;

		if (estoy_en_tablero(pos, Tablero::get_numCas())&&!casilla_me_da_jaque(pos)) {
			posibles.push_back(pos); 
		}

	}
		return posibles;
}

 bool Rey::casilla_me_da_jaque(Posicion& pos) {
     //Comprobamos el color con el operador ternario para obtener las piezas blancas o negras
     const vector<Pieza*>& piezas_enemigas = (color == BLANCO) ? Tablero::get_piezas_N() : Tablero::get_piezas_B();

     //Recorremos todas las piezas enemigas con un for de rango
     for (Pieza* a : piezas_enemigas) {

         //Evitamos al rey enemigo
         if (a->get_tipo() == Tipo::REY) continue;

         //COMPROBACIONE SPECIAL PARRA EL PEON
         if (a->get_tipo() == Tipo::PEON) {
             //LA LINEA RECTA DEL PEON, ES UNA POSICION POSIBLE PERO NO ES JAQUE (SI ESTA EN LA MISMA COLUMNA ES LINE RECTA)
             if (pos.Columna == a->get_posicion().Columna) continue;

             //LAS DIAGONALES, NO SON POSICION POSIBLE, PORQUE SOLO LO SON SI HAY UNA PIEZA AHI
             //PERO NO TE PUEDES MOVER PORQUE TE DA JAQUE
             int direccion = (a->get_color() == BLANCO) ? 1 : -1;

             //SI LA FILA ES LA CORRESPONDIENTE A LA DIAGONAL (direccion para controlar el color) 
             //Y LA COLUMNA ES UNA DE LAS CONTIUGUAS, ESTA EN LA DIAGONAL!!!!
             if (pos.Fila == a->get_posicion().Fila + direccion && abs(pos.Columna - a->get_posicion().Columna) == 1) {
                 return true;
             }

         }

         //verifica si alguna de las posiciones posibles de las piezas enemigas coincide con la posicion del rey
         for (const Posicion& b : a->posiciones_posibles_conrey()) {

             if (b == pos) {
                 return true;
             }

         }
     }
     return false;//Valor de retorno si no hay jaque
 }