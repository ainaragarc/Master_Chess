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

    anadir_piezas_B(piezas_B, new Peon(BLANCO,{1,}));
    anadir_piezas_B(piezas_B, new Caballo(BLANCO,{0,1}));
    anadir_piezas_B(piezas_B, new Torre(BLANCO,{0,0}));
    anadir_piezas_B(piezas_B, new Alfil(BLANCO,{0,2}));
    anadir_piezas_B(piezas_B, new Rey(BLANCO,{0,4}));
    anadir_piezas_B(piezas_B, new Dama(BLANCO,{0,3}));

    //CASO GARDNER
    anadir_piezas_N(piezas_N, new Peon(NEGRO,{2,}));
    anadir_piezas_N(piezas_N, new Caballo(NEGRO, {4,1}));
    anadir_piezas_N(piezas_N, new Torre(NEGRO, {4,0}));
    anadir_piezas_N(piezas_N, new Alfil(NEGRO, {4,2}));
    anadir_piezas_N(piezas_N, new Rey(NEGRO, {4,4}));
    anadir_piezas_N(piezas_N, new Dama(NEGRO,{4,3}));

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
void Tablero::anadir_piezas_B(vector<Pieza*>& equipo, Pieza* pieza) {
    
    Tipo t=pieza->get_tipo();
    if (t == Tipo::PEON) {//comprobamos si es tipo peon
        for (int j = 0; j < 5; j++) {
            Peon* nuevo_peon = new Peon(BLANCO, { 1,j });//si es peon, creamos 5 nuevos peones
            equipo.push_back(nuevo_peon);
            
        }
        
    }
    else { equipo.push_back(pieza); };
       
}

void Tablero::anadir_piezas_N(vector<Pieza*>& equipo, Pieza* pieza) {
    Tipo t = pieza->get_tipo();
    if (t == Tipo::PEON) {//comprobamos si es tipo peon
        for (int j = 0; j < 5; j++) {
            Peon* nuevo_peon = new Peon(NEGRO, { 3,j });//si es peon, creamos 5 nuevos peones en la posicion de negro
            equipo.push_back(nuevo_peon);
           
        }
        
    }
    else { equipo.push_back(pieza); }



}
//comprobacion de posicion inicial en el tablero
void Tablero::Pruebapiezas() {
    for (auto i : piezas_B) {
        cout << "Hay una pieza de tipo: " << static_cast<int>(i->get_tipo()) <<" en : ("<<i->get_posicion().Fila<<","<< i->get_posicion().Columna<<")"<< endl;
    }
    for (auto i : piezas_B) {
        cout << "Hay una pieza de tipo: " << static_cast<int>(i->get_tipo()) << " en : (" << i->get_posicion().Fila << "," << i->get_posicion().Columna << ")" << endl;
    }
}

bool Tablero::hay_pieza(Posicion& pos) {
    return (hay_pieza_BLANCA(pos) || hay_pieza_NEGRA(pos));
}

 bool Tablero::hay_pieza_BLANCA(Posicion& pos) {
     for (auto& i : piezas_N) {
         if (i->get_posicion().Fila == pos.Fila && i->get_posicion().Columna == pos.Columna) {
             return true;
         }
     }
     return false;
}

 bool Tablero::hay_pieza_NEGRA(Posicion& pos) {
     for (auto& i : piezas_B) {
         if (i->get_posicion().Fila == pos.Fila && i->get_posicion().Columna == pos.Columna) {
             return true;
         }
     }
     return false;
}
 
 Tipo Tablero::tipo_pieza(Posicion& pos) {
     for (auto& i : piezas_N) {
         if (i->get_posicion().Fila == pos.Fila && i->get_posicion().Columna == pos.Columna) {
             return i->get_tipo();
         }
     }
     for (auto& i : piezas_B) {
         if (i->get_posicion().Fila == pos.Fila && i->get_posicion().Columna == pos.Columna) {
             return i->get_tipo();
         }
     }
	 return Tipo::VACIO;
 }

 void Tablero::PRUEBADEMOVIMIENTO() {

     Alfil* mipieza3 = new Alfil(BLANCO, { 1,2 });
     Alfil* mipieza2 = new Alfil(BLANCO, { 2,1 });
     Rey* mipieza = new Rey(NEGRO, { 3,1 });

     Rey* R = new Rey(BLANCO, { 2,2 });

     anadir_piezas_B(piezas_B, mipieza3);
	 anadir_piezas_B(piezas_B, mipieza2);
     anadir_piezas_N(piezas_N, mipieza);

	 anadir_piezas_B(piezas_B, R);

     std::cout << " esta en " << mipieza->get_posicion().Fila << ":" << mipieza->get_posicion().Columna << std::endl;
     Posicion posfinal{ 2,1 };
     mipieza->mueve(posfinal);
     std::cout << " \nesta en " << mipieza->get_posicion().Fila << ":" << mipieza->get_posicion().Columna << std::endl;
     mipieza->mueve(posfinal);
     
 }

 void Tablero::comer_pieza(Posicion pos) {
     // buscar en piezas blancas
     for (auto it = piezas_B.begin(); it != piezas_B.end(); ++it) {
         if ((*it)->get_posicion().Fila == pos.Fila && (*it)->get_posicion().Columna == pos.Columna) {
             delete* it;
             piezas_B.erase(it);
             std::cout << "Pieza blanca eliminada en (" << pos.Fila << ", " << pos.Columna << ")\n";
             return;
         }
     }

     // buscar en piezas negras
     for (auto it = piezas_N.begin(); it != piezas_N.end(); ++it) {
         if ((*it)->get_posicion().Fila == pos.Fila && (*it)->get_posicion().Columna == pos.Columna) {
             delete* it;
             piezas_N.erase(it);
             std::cout << "Pieza negra eliminada en (" << pos.Fila << ", " << pos.Columna << ")\n";
             return;
         }
     }
 }