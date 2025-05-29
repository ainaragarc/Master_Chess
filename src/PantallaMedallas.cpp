#include "PantallaMedallas.h"
#include "BrochaPantallas.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include "Bot.h"


PantallaMedallas::PantallaMedallas(GestorPantallas* gestor) : gestor(gestor) {
    float ancho_total = 0.5f;
    float alto_boton = 0.15f;
    float margen = 0.05f;
    float x1 = 0.4f;
    float x2 = x1 + ancho_total;

    float y_top = -0.7f;

    botones.push_back({ "<- VOLVER",{ x1, y_top },{ x2, y_top + alto_boton } });
    
}


void PantallaMedallas::dibuja() {
    // Dibuja fondo
    BrochaPantallas::insertarimagen("imagenes/Fondo_medallas.png", 1.0, 1.0, 1.0, 1.0);
  
    //Funcion dibuja_medallas
    dibuja_medallas();

    // Dibujo botón
    for (auto& b : botones)
        b.dibujar();
}

void PantallaMedallas::dibuja_medallas() {
    //Declaración coordenadas medallas
    if (Bot::tiene_medalla_amarilla()) {
        //Medalla amarilla
        BrochaPantallas::insertarimagen("imagenes/Medalla amarilla.png", 0.9, 0.0, 0.1, 0.9);
    }

    if (Bot::tiene_medalla_fuego()) {
        //Medalla fuego
        BrochaPantallas::insertarimagen("imagenes/Medalla fuego.png", 0.0, 0.05, 0.93, 0.95);
    }

    if (Bot::tiene_medalla_azul()) {
        //Medalla azul
        BrochaPantallas::insertarimagen("imagenes/Medalla azul.png", 0.55, 0.90, 0.55, 0.05);
    }
}

void PantallaMedallas::raton(int button, int state, int x, int y) {
    if (!BrochaPantallas::es_clic_izquierdo(button, state)) return;

    Coordenada click = BrochaPantallas::convertir_click_a_opengl(x, y);

    if (botones[0].clic_en(click.x, click.y)) {
        accion_pendiente = Medallas::VOLVER;
    }
}