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


void Tablero::inicializa_piezas_GARDNER() {

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

void Tablero::inicializa_piezas_BABY() {

    anadir_piezas_B(piezas_B, new Peon(BLANCO, { 1, }));
    anadir_piezas_B(piezas_B, new Caballo(BLANCO, { 0,1 }));
    anadir_piezas_B(piezas_B, new Torre(BLANCO, { 0,0 }));
    anadir_piezas_B(piezas_B, new Alfil(BLANCO, { 0,2 }));
    anadir_piezas_B(piezas_B, new Rey(BLANCO, { 0,4 }));
    anadir_piezas_B(piezas_B, new Dama(BLANCO, { 0,3 }));

    //CASO BABY
    anadir_piezas_N(piezas_N, new Peon(NEGRO, { 2,}));
    anadir_piezas_N(piezas_N, new Caballo(NEGRO, { 4,3 }));
    anadir_piezas_N(piezas_N, new Torre(NEGRO, { 4,4 }));
    anadir_piezas_N(piezas_N, new Alfil(NEGRO, { 4,2 }));
    anadir_piezas_N(piezas_N, new Rey(NEGRO, { 4,0 }));
    anadir_piezas_N(piezas_N, new Dama(NEGRO, { 4,1 }));

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
     for (auto& i : piezas_B) {
         if (i->get_posicion() == pos ) {
             return true;
         }
     }
     return false;
}

 bool Tablero::hay_pieza_NEGRA(Posicion& pos) {
     for (auto& i : piezas_N) {
         if (i->get_posicion() == pos) {
             return true;
         }
     }
     return false;
}
 
 Tipo Tablero::tipo_pieza(Posicion& pos) {
     for (auto& i : piezas_N) {
         if (i->get_posicion()== pos) {
             return i->get_tipo();
         }
     }
     for (auto& i : piezas_B) {
         if (i->get_posicion()== pos) {
             return i->get_tipo();
         }
     }
	 return Tipo::VACIO;
 }

 Posicion Tablero::pos_Rey(Color col) {
	 auto piezas = (col == BLANCO) ? piezas_B : piezas_N;
	 for (auto& i : piezas) {
		 if (i->get_tipo() == Tipo::REY) {
			 return i->get_posicion();
		 }
	 }
 }


 bool Tablero::Jaque(Color col) {
	 auto enemigos = (col == BLANCO) ? piezas_N : piezas_B;
	 Posicion pos_rey = pos_Rey(col);

     for (auto& a : enemigos) {
         for (auto& b : a->posiciones_posibles_conrey()) {
             if (b == pos_rey) {return true;}
         }
     }

	 return false; // El rey no está en jaque
 }
 Pieza* Tablero::get_pieza_en_pos(const Posicion& pos) {
     for (Pieza* p : piezas_B) if (p->get_posicion() == pos) return p;
     for (Pieza* p : piezas_N) if (p->get_posicion() == pos) return p;
     return nullptr;
 }

 bool Tablero::es_jaque_mate(Color color) {
     if (!Jaque(color)) return false;//Se descarta jaque mate si no hay jaque
     //Definimos las piezas propias y enemigas con la comprobación del color actual
     auto& piezas_propias = (color == BLANCO) ? piezas_B : piezas_N;
     auto& piezas_enemigas = (color == BLANCO) ? piezas_N : piezas_B;

     //Probamos todos los movimientos posibles
     for (Pieza* pieza : piezas_propias) {
         Posicion origen = pieza->get_posicion();
         std::vector<Posicion> movimientos = pieza->posiciones_posibles_conrey();

         for (const Posicion& destino : movimientos) {
             // Guardamos la pieza que habia en el destino
             Pieza* capturada = get_pieza_en_pos(destino);
             bool fue_capturada = false;

             // Simulamos capturar la pieza enemiga
             if (capturada != nullptr) {
                 //Hacemos uso de iteradores y de la función find de <vector> para buscar el puntero "capturada"
                 auto it = std::find(piezas_enemigas.begin(), piezas_enemigas.end(), capturada);
                 if (it != piezas_enemigas.end()) {
                     piezas_enemigas.erase(it);//Eliminamos la pieza como si hubiese sido capturada
                     fue_capturada = true;
                 }
             }

             pieza->mueve(destino); // simulamos el movimiento
             bool sigue_en_jaque = Jaque(color); // comprobamos si sigue en jaque
             pieza->mueve(origen); // revertimos movimiento

             if (fue_capturada) {
                 piezas_enemigas.push_back(capturada); // restauramos la pieza capturada
             }

             if (!sigue_en_jaque) return false; // hay al menos un movimiento legal y no es jaque mate
         }
     }

     return true; // Si no hay forma de salir del jaque es jaque mate
 }


 Pieza* Tablero::comer_pieza(Posicion pos) {
     //Referencia a piezas blancas (para editarlas directamente)
     auto& piezas_blancas = get_piezas_B();
     //Comprobamos si hay una pieza en la posición de destino
     //Lo hacemos con iteradores para poder hacer uso de la función erase que recibe un iterador
     for (auto it = piezas_blancas.begin(); it != piezas_blancas.end(); ++it) {
         if ((*it)->get_posicion() == pos) {
             Pieza* capturada = *it;
             piezas_blancas.erase(it);
             return capturada;
         }
     }

     //Hacemos lo mismo con las piezas negras
     auto& piezas_negras = get_piezas_N();
     for (auto it = piezas_negras.begin(); it != piezas_negras.end(); ++it) {
         if ((*it)->get_posicion() == pos) {
             Pieza* capturada = *it;
             piezas_negras.erase(it);
             return capturada;
         }
     }

     return nullptr; // No se encontró ninguna pieza
 }
