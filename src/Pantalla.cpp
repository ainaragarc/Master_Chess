#include "Pantalla.h"
#include "BrochaPantallas.h"

void Pantalla::dibuja() {

}
void Pantalla::actualiza(){

}

void Pantalla::tecla(unsigned char key) {

}

void Pantalla::raton(int button, int state, int x, int y) {

}

//funcion para dibujar
void Boton::dibujar() const {
    BrochaPantallas::dibujar_barra_carga(1.0f, x1, y1, x2, y2, 0.3f, 0.3f, 0.7f);
    float ancho = x2 - x1;
    float alto = y2 - y1;
    BrochaPantallas::dibujar_texto(texto, x1 + ancho * 0.25f, y1 + alto * 0.25f);
}