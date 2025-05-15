#include "GestorEstados.h"

void GestorEstados::inicializa() { //podemos usarla para inicializar, aunque se puede inicializar en otro sitio
   if (estado_actual == JUGANDO)
        mundo.inicializa();
}

void GestorEstados::dibuja() {
    switch (estado_actual) {
    case MENU:
        // dibujar menú
        break;
    case JUGANDO:
        mundo.dibuja();
        break;
    case PAUSA:
        // dibujar pausa
        break;
    default:
        break;
    }
}

void GestorEstados::mueve() {
   if (estado_actual == JUGANDO)
        mundo.mueve();
}

void GestorEstados::tecla(unsigned char key) {
   //usar para cambiar estados
}

void GestorEstados::raton(int button, int state, int x, int y) {
    if (estado_actual == JUGANDO)
        mundo.gestionar_click(button, state, x, y);
}