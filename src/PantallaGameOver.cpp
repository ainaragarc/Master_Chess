#include "PantallaGameOver.h"
#include "BrochaPantallas.h"
#include "freeglut.h"
#include "Mundo.h"

PantallaGameOver::PantallaGameOver(GestorPantallas* gestor, Mundo* mundo, const std::string& ganador) 
    : gestor(gestor), mundo(mundo), mensaje(ganador) {
    float ancho_total = 0.5f;
    float alto_boton = 0.15f;
    float margen = 0.05f;
    float x1 = 0.4f;
    float x2 = x1 + ancho_total;

    float y_top = -0.7f;

    botones.push_back({ "<- VOLVER",{ x1, y_top },{ x2, y_top + alto_boton } });
}

void PantallaGameOver::dibuja() {
    BrochaPantallas::configurar_proyeccion_pantalla(4.0);

    BrochaPantallas::limpiar_pantalla(ColorTextos(0.1f, 0.1f, 0.2f));
    if (mundo) mundo->dibuja();  //dibujamos el tablero actual

    BrochaPantallas::configurar_proyeccion_pantalla(1.0);
   
    if (mensaje == "BLANCAS") {
        BrochaPantallas::insertarimagen("imagenes/Victoria para blancas.png", 0.5, 0.5, 0.5, 0.5);
    }
    if (mensaje == "NEGRAS") {
        BrochaPantallas::insertarimagen("imagenes/Victoria para negras.png", 0.5, 0.5, 0.5, 0.5);
    }
    if (mensaje == "TABLAS") {
        BrochaPantallas::insertarimagen("imagenes/Tablas.png", 0.5, 0.5, 0.5, 0.5);
    }
    
    //Dibujo boton
    for (auto& b : botones)
        b.dibujar();
   
}

void PantallaGameOver::raton(int button, int state, int x, int y) {
    if (!BrochaPantallas::es_clic_izquierdo(button, state)) return;

    Coordenada click = BrochaPantallas::convertir_click_a_opengl(x, y);

    if (botones[0].clic_en(click.x, click.y)) {
        accion_pendiente = Game_over::VOLVER;
    }
}