#include "Peon.h"
#include "pieza.h"
#include <vector>
#include "tablero.h"

#include <iostream>

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

    if (estoy_en_tablero(pos, Tablero::get_numCas()) && Tablero::tipo_pieza(pos) != Tipo::REY) {

        posibles.push_back(pos);

        // avance doble
		if ((!Tablero::hay_pieza(pos)) && (posicion.Fila == fila_inicial)){
			pos += direccion;
            if (Tablero::tipo_pieza(pos) != Tipo::REY) {
				posibles.push_back(pos);
            }
        }
    }

    for (auto& d : diagonales) {
        Posicion diag = posicion;
        diag += d;

        if (estoy_en_tablero(diag, Tablero::get_numCas()) &&Tablero::hay_pieza(diag) &&Tablero::tipo_pieza(diag) != Tipo::REY ) {
            posibles.push_back(diag);
			cout << "holamigalletitalotus";
        }
    }

    for (auto& i : posibles) {
        std::cout << "posible: " << i.Fila << ":" << i.Columna << std::endl;
    }

    return posibles;
}
