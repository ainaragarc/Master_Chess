#pragma once
#include "Pantalla.h"

class GestorPantallas {
private:
    Pantalla* pantalla_actual = nullptr;
public:
    void set_pantalla(Pantalla* nueva); //funcion para establecer pantallas

    void dibuja(); //funcion para dibujar pantallas
    void actualiza(); //funcion para actualizar pantallas
    void tecla(unsigned char key); //funcion para usar teclas en las pantallas
    void raton(int button, int state, int x, int y); //funcion para usar el raton en las pantallas
    void mover_raton(int x, int y);

    // funcion para obtener la pantalla actual
    Pantalla* get_pantalla() { return pantalla_actual; }
};