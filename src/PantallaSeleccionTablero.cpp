#include "PantallaSeleccionTablero.h"
#include "BrochaPantallas.h"

PantallaSeleccionTablero::PantallaSeleccionTablero(GestorPantallas* gestor) : gestor(gestor) {
    botones.push_back({ "TABLERO BABY", Coordenada{-0.5f,  0.1f}, Coordenada{0.3f,  0.25f } });
    botones.push_back({ "TABLERO GARDNER",Coordenada{-0.5f, -0.2f}, Coordenada{0.3f, -0.05f }});
}

void PantallaSeleccionTablero::dibuja() {
    BrochaPantallas::limpiar_pantalla(Color(0.15f, 0.15f, 0.15f));
    Color colorTexto = Color(1.0f, 1.0f, 1.0f);
    BrochaPantallas::dibujar_texto("SELECCIONA TABLERO", Coordenada{ -0.4f, 0.4f }, colorTexto);
}

void PantallaSeleccionTablero::dibuja() {
    BrochaPantallas::limpiar_pantalla(0.15f, 0.15f, 0.15f);
    BrochaPantallas::dibujar_texto("SELECCIONA TABLERO", -0.4f, 0.4f);
    for (auto& b : botones)
        b.dibujar();
}

void PantallaSeleccionTablero::raton(int button, int state, int x, int y) {
    if (!BrochaPantallas::es_clic_izquierdo(button, state)) return;

    Coordenada click = BrochaPantallas::convertir_click_a_opengl(x, y);

    if (botones[0].clic_en(click.x, click.y)) {
        accion_pendiente = AccionTablero::TABLERO_BABY;
    }
    else if (botones[1].clic_en(click.x, click.y)) {
        accion_pendiente = AccionTablero::TABLERO_GARDNER;
    }
}