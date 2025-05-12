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

    añadir_piezas_B(piezas_B, new Peon(BLANCO,{1,}));
    añadir_piezas_B(piezas_B, new Caballo(BLANCO,{0,1}));
    añadir_piezas_B(piezas_B, new Torre(BLANCO,{0,0}));
    añadir_piezas_B(piezas_B, new Alfil(BLANCO,{0,2}));
    añadir_piezas_B(piezas_B, new Rey(BLANCO,{0,4}));
    añadir_piezas_B(piezas_B, new Dama(BLANCO,{0,3}));

    //CASO GARDNER
    añadir_piezas_N(piezas_N, new Peon(NEGRO,{2,}));
    añadir_piezas_N(piezas_N, new Caballo(NEGRO, {4,1}));
    añadir_piezas_N(piezas_N, new Torre(NEGRO, {4,0}));
    añadir_piezas_N(piezas_N, new Alfil(NEGRO, {4,2}));
    añadir_piezas_N(piezas_N, new Rey(NEGRO, {4,4}));
    añadir_piezas_N(piezas_N, new Dama(NEGRO,{4,3}));

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
void Tablero::añadir_piezas_B(vector<Pieza*>& equipo, Pieza* pieza) {
    
    Tipo t=pieza->get_tipo();
    if (t == Tipo::PEON) {//comprobamos si es tipo peon
        for (int j = 0; j < 5; j++) {
            Peon* nuevo_peon = new Peon(BLANCO, { 1,j });//si es peon, creamos 5 nuevos peones
            equipo.push_back(nuevo_peon);
            
        }
        
    }
    else { equipo.push_back(pieza); };
       
}

void Tablero::añadir_piezas_N(vector<Pieza*>& equipo, Pieza* pieza) {
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


/*void Tablero::PRUEBADEMOVIMIENTO() {
    
    Alfil* mipieza = new Alfil({ 1, 1 });
    Alfil* mipieza2 = new Alfil({ 3, 3 });

    piezas_N.push_back(mipieza);
    piezas_N.push_back(mipieza2);

    Posicion pos3{ 2,2 };
    if (hay_pieza(pos3)) { std::cout << "hola"; }

    std::cout << "mi alfiil esta en " << mipieza->get_posicion().Columna << ":" << mipieza->get_posicion().Fila << std::endl;
    Posicion posfinal{ 1,2 };
    mipieza->mueve(posfinal);
    std::cout << "el alfil sigue porque posicion incorrecta " << mipieza->get_posicion().Columna << ":" << mipieza->get_posicion().Fila << std::endl;
    posfinal = { 2,2 };
    mipieza->mueve(posfinal);
    std::cout << "ahora mi pieza esta en " << mipieza->get_posicion().Columna << ":" << mipieza->get_posicion().Fila << std::endl;
    posfinal = { 4,4 };
    mipieza->mueve(posfinal);
    std::cout << "el alfil sigue porque posicion incorrecta " << mipieza->get_posicion().Columna << ":" << mipieza->get_posicion().Fila << std::endl;
    posfinal = { 3,3 };
    mipieza->mueve(posfinal);
    std::cout << "ahora mi pieza esta en " << mipieza->get_posicion().Columna << ":" << mipieza->get_posicion().Fila << std::endl;
   
    /*
    Peon* mipiezaB = new Peon({ 1, 1 });
    Peon* mipieza2B = new Peon({ 0, 0 });
    Peon* mipieza2N = new Peon({ 1, 2 });
    Peon* mipiezaN = new Peon({ 3, 3 });

    piezas_B.push_back(mipiezaB);
    piezas_B.push_back(mipieza2B);
    piezas_N.push_back(mipiezaN);
    piezas_N.push_back(mipieza2N);

    Posicion pos3{ 3,1 };

    mipieza2N->mueve(pos3);
    std::cout << "mi alfiil esta en " << mipiezaB->get_posicion().Columna << ":" << mipiezaB->get_posicion().Fila << std::endl;

    mipiezaN->mueve(pos3);
    std::cout << "mi alfiil esta en " << mipiezaB->get_posicion().Columna << ":" << mipiezaB->get_posicion().Fila << std::endl;

    mipieza2B->mueve(pos3);
    std::cout << "mi alfiil esta en " << mipiezaB->get_posicion().Columna << ":" << mipiezaB->get_posicion().Fila << std::endl;

    mipiezaB->mueve(pos3);

    std::cout << "mi alfiil esta en " << mipiezaB->get_posicion().Columna << ":" << mipiezaB->get_posicion().Fila << std::endl;

    Posicion posfinal{ 1,2 };

    *//*
}*/