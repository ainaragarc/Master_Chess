#include "Peon.h"
#include "pieza.h"
#include <vector>
#include "tablero.h"
#include "alfil.h"
#include "torre.h"
#include "caballo.h"
#include "dama.h"

vector<Posicion> Peon::posiciones_posibles_conrey() {
    vector<Posicion> posibles;

    Posicion direccion = { 1, 0 };  // Direcci�n hacia abajo (blanco)
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

        if (estoy_en_tablero(diag, Tablero::get_numCas()) &&Tablero::hay_pieza(diag) ) {
            posibles.push_back(diag);
        }
    }

    return posibles;
}

void Peon::mueve(Posicion posicion_final) {
    posicion = posicion_final;

        int p;
        (color == Color::BLANCO) ? p = Tablero::get_numCas() - 1 : p = 0;
        if (posicion.Fila == p) {
            
            if (color == Color::BLANCO) {
                unsigned char tipo;
                std::cout << "CORONAR EL PEON" << std::endl;
                std::cout << "c: caballo, t: torre, a: alfil, d: dama";
                do {
                    std::cin >> tipo;
                } while (tipo != 'c' && tipo != 't' && tipo != 'a' && tipo != 'd');
                promover(tipo);
            }

            else { //EL BOT PROMUEVE A LA DAMA, SOLUCION A MEJORAR
                //SOLO FUNCIONA PORQUE EL BOT SOLO JUEGA CON NEGRAS
                unsigned char tipo = 'd';
                promover(tipo);

            }
           
            //PROBLEMA, HAY QUE ESTABLECER QUE EL BOT PROMUEVA A ALGO
            //PROBLEMA 2, IMPLEMENTACION IN GAME, NO POR CONSOLA
            //PROBLEMA 3, DEBERIA MOSTRARSE ALGO POR PANTALLA, digo yo
        }
}

void Peon::promover(unsigned char &tipo)  {
    Pieza* pieza = nullptr;
    switch (tipo) {
    case 'c':
              pieza = new Caballo(color, posicion);
             break;
    case 't':
             pieza = new Torre(color, posicion);
            break;
    case 'a':
             pieza = new Alfil(color, posicion);
            break;
    case 'd':
             pieza = new Dama(color, posicion);
            break;
        default:
            return;
    }

    auto& v = (color == BLANCO) ? Tablero::get_piezas_B() : Tablero::get_piezas_N();
    for (auto a = v.begin(); a != v.end(); ++a) {
        if (*a == this) {
            delete *a;
            *a = pieza;
            break;
        }
    }

}
