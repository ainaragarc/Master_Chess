#include "GestorPantallas.h"

void GestorPantallas::set_pantalla(Pantalla* nueva) {
    pantalla_actual = nueva;
}

void GestorPantallas::dibuja() {
    if (pantalla_actual) pantalla_actual->dibuja();
}

void GestorPantallas::actualiza() {
    if (pantalla_actual) pantalla_actual->actualiza();
}

void GestorPantallas::tecla(unsigned char key) {
    if (pantalla_actual) pantalla_actual->tecla(key);
}

void GestorPantallas::raton(int button, int state, int x, int y) {
    if (pantalla_actual) pantalla_actual->raton(button, state, x, y);
}