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
    ColorTextos colorRecuadro = casilla_seleccionada ? ColorTextos(1.0f,0.8f,0.0f) : ColorTextos(0.208f,0.416f,0.737f);
    BrochaPantallas::dibujar_barra_carga(1.0f, desde, hasta, colorRecuadro);
    float ancho = hasta.x - desde.x;
    float alto = hasta.y - desde.y;
    Coordenada centroTexto = { desde.x + ancho * 0.25f, desde.y + alto * 0.25f };
    ColorTextos colorTexto = ColorTextos(1.0f, 1.0f, 1.0f);
    BrochaPantallas::dibujar_texto(texto, centroTexto, colorTexto);
}

//funcion que devuelve true si se hace click dentro del boton
bool Boton::clic_en(float x, float y) const {
    return x >= desde.x && x <= hasta.x && y >= desde.y && y <= hasta.y;
}

void Pantalla::mover_raton(int x, int y) {
    Coordenada pos = BrochaPantallas::convertir_click_a_opengl(x, y);
    for (auto& b : botones)
        b.set_casilla_seleccionada(b.clic_en(pos.x, pos.y));
}