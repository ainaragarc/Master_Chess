#include "Peon.h"
#include "pieza.h"
#include <vector>
#include "tablero.h"

vector<Posicion> Peon::posiciones_posibles() {
    vector<Posicion> posibles;

    Posicion direccion = { 1, 0 };  // Dirección hacia abajo (blanco)
    Posicion diagonales[2] = { {1, 1}, {1, -1} };  // Diagonales hacia delante
    int fila_inicial = 1;

    if (color == Color::NEGRO) {
        direccion.Fila = -1;
		for (auto& a : diagonales) { a.Fila = -a.Fila; }
		fila_inicial = Tablero::get_numCas() - 2; //5 casillas y deberia empezar en la 3
    }

    // Paso 1 adelante
    Posicion pos = posicion;
	pos += direccion;

    if (estoy_en_tablero(pos, Tablero::get_numCas()) && (!Tablero::hay_pieza(pos))) {

        posibles.push_back(pos);

        // avance doble : no permitido por reglamento de tipo de juego, lo dejamos por si acaso
        /*
		if ((posicion.Fila == fila_inicial)){
			pos += direccion;
            if ((!Tablero::hay_pieza(pos))) {
				posibles.push_back(pos);
            }
        }
        */
    }

    for (auto& d : diagonales) {
        Posicion diag = posicion;
        diag += d;

        if (estoy_en_tablero(diag, Tablero::get_numCas()) &&Tablero::hay_pieza(diag) &&Tablero::tipo_pieza(diag) != Tipo::REY ) {
            posibles.push_back(diag);
        }
    }

    return posibles;
}
