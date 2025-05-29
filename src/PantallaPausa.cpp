#include "PantallaPausa.h"
#include "BrochaPantallas.h"
#include <iostream>

PantallaPausa::PantallaPausa(GestorPantallas* gestor, Mundo* mundo)
    : gestor(gestor), mundo(mundo) {

    float ancho_total = 0.6f;
    float alto_boton = 0.15f;
    float margen = 0.05f;
    float x1 = -ancho_total / 2.0f;
    float x2 = ancho_total / 2.0f;

    float y_top = 0.0f;

    botones.push_back({ "REANUDAR",{ x1, y_top },{ x2, y_top + alto_boton } });
    botones.push_back({ "RENDIRSE",{ x1, y_top - 1 * (alto_boton + margen) }, { x2, y_top - 1 * (alto_boton + margen) + alto_boton } });
    botones.push_back({ "CERRAR JUEGO", { x1, y_top - 2 * (alto_boton + margen) }, { x2, y_top - 2 * (alto_boton + margen) + alto_boton } });
}

void PantallaPausa::dibuja() {

    BrochaPantallas::configurar_proyeccion_pantalla(4.0);

    BrochaPantallas::limpiar_pantalla(ColorTextos(0.1f, 0.1f, 0.2f));
    if (mundo) mundo->dibuja();  //dibujamos el tablero actual
    BrochaPantallas::configurar_proyeccion_pantalla(1.0);

    //hacemos un recuadro para la pausa

    BrochaPantallas::dibujar_recuadro(
        { -0.4f, -0.5f },
        { 0.4f,  0.55f },
        ColorTextos(0.9f, 0.9f, 0.9f),
        0.95f
    );

    //BrochaPantallas::dibujar_texto("PAUSA", Coordenada{ -0.15f, 0.7f }, ColorTextos(0.0f, 0.0f, 0.0f));
    BrochaPantallas::insertarimagen("imagenes/Pausa-29-5-2025.png", 0.4, -0.15 ,0.4, 0.55);

    for (auto& b : botones)
        b.dibujar();
}

void PantallaPausa::raton(int button, int state, int x, int y) {
    if (!BrochaPantallas::es_clic_izquierdo(button, state)) return;

    Coordenada pos = BrochaPantallas::convertir_click_a_opengl(x, y);

    if (botones[0].clic_en(pos.x, pos.y)) accion = AccionPausa::REANUDAR;
    else if (botones[1].clic_en(pos.x, pos.y)) accion = AccionPausa::RENDIRSE;
    else if (botones[2].clic_en(pos.x, pos.y)) accion = AccionPausa::SALIR_JUEGO;
}