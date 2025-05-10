#pragma once
#include "Tablero.h"
#include "peon.h"
#include "alfil.h"
#include "caballo.h"
#include "dama.h"
#include "rey.h"
#include "torre.h"
#include "freeglut.h"
#include<vector>
#include <iostream>


vector<Pieza*> Tablero::piezas_B;
vector<Pieza*> Tablero::piezas_N;


void Tablero::inicializa_piezas() {

    a�adir_piezas_B(piezas_B, new Peon());
    a�adir_piezas_B(piezas_B, new Caballo());
    a�adir_piezas_B(piezas_B, new Torre());
    a�adir_piezas_B(piezas_B, new Alfil());
    a�adir_piezas_B(piezas_B, new Rey());
    a�adir_piezas_B(piezas_B, new Dama());

    a�adir_piezas_N(piezas_N, new Peon());
    a�adir_piezas_N(piezas_N, new Caballo());
    a�adir_piezas_N(piezas_N, new Torre());
    a�adir_piezas_N(piezas_N, new Alfil());
    a�adir_piezas_N(piezas_N, new Rey());
    a�adir_piezas_N(piezas_N, new Dama());
    //Prueba:
    for (auto i : piezas_B) {
        cout << "Pieza: " << static_cast<int>(i->get_tipo()) << " Color: " << static_cast<int>(i->get_color()) << " Cantidad: " << i->get_cantidad() << endl;
    }
    cout << "\n";
    for (auto i : piezas_N) {
        cout << "Pieza: " << static_cast<int>(i->get_tipo()) << " Color: " << static_cast<int>(i->get_color()) << " Cantidad: " << i->get_cantidad() << endl;
    }

}

//funcion para limpiar mas el codigo de inicializa pieza
void Tablero::a�adir_piezas_B(vector<Pieza*>& equipo, Pieza* pieza) {
    equipo.push_back(pieza);
    equipo.back()->set_color(BLANCO);//inicializamos el color de la pieza como blanco
    equipo.back()->set_tipo();
    equipo.back()->set_cantidad();//inicializamos la cantidad de cada pieza
    equipo.back()->set_posicion_ini();
}

void Tablero::a�adir_piezas_N(vector<Pieza*>& equipo, Pieza* pieza) {
    equipo.push_back(pieza);
    equipo.back()->set_color(NEGRO);//inicializamos el color de la pieza como negro
    equipo.back()->set_tipo();
    equipo.back()->set_cantidad();

}

bool Tablero::hay_pieza(Posicion& pos) {
    for (auto& i : piezas_N) {
        if (i->get_posicion().Fila == pos.Fila && i->get_posicion().Columna == pos.Columna) {
            return true;
        }
    }
    for (auto& i : piezas_B) {
        if (i->get_posicion().Fila == pos.Fila && i->get_posicion().Columna == pos.Columna) {
            return true;
        }
    }
    return false;
}
