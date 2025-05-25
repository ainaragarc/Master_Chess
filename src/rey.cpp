#include "rey.h"
#include "pieza.h"
#include <vector>
#include "tablero.h"

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

         //verifica si alguna de las posiciones posibles de las piezas enemigas coincide con la posicion del rey
         for (const Posicion& b : a->posiciones_posibles_conrey()) {
             if (b == pos) {
                 return true;
             }
         }
     }

     return false;//Valor de retorno si no hay jaque
 }