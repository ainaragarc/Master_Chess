#include "PantallaSeleccionBot.h"
#include "BrochaPantallas.h"

PantallaSeleccionBot::PantallaSeleccionBot(GestorPantallas* gestor) : gestor(gestor) {
    botones.push_back({ "VS BOT", Coordenada{-0.5f,  0.1f}, Coordenada{0.3f,  0.25f } });
    botones.push_back({ "VS AMIGO",Coordenada{-0.5f, -0.2f}, Coordenada{0.3f, -0.05f } });
    botones.push_back({ "MEDALLAS",Coordenada{-0.5f, -0.45f}, Coordenada{0.3f, -0.30f } });
    botones.push_back({ "<- VOLVER", Coordenada{-0.5f, -0.65f}, Coordenada{0.3f, -0.50f} });
}

void PantallaSeleccionBot::dibuja() {
    BrochaPantallas::configurar_proyeccion_pantalla(1.0);

    BrochaPantallas::limpiar_pantalla(ColorTextos(0.15f, 0.15f, 0.15f));
    ColorTextos colorTexto = ColorTextos(1.0f, 1.0f, 1.0f);
    BrochaPantallas::dibujar_texto("SELECCIONA ADVERSARIO", Coordenada{ -0.4f, 0.4f }, colorTexto);
    for (auto& b : botones)
        b.dibujar();
}

void PantallaSeleccionBot::raton(int button, int state, int x, int y) {
    if (!BrochaPantallas::es_clic_izquierdo(button, state)) return;

    Coordenada click = BrochaPantallas::convertir_click_a_opengl(x, y);

    if (botones[0].clic_en(click.x, click.y)) {
        accion_pendiente = AccionBot::VS_BOT;
    }
    else if (botones[1].clic_en(click.x, click.y)) {
        accion_pendiente = AccionBot::VS_AMIGO;
    }
    else if (botones[2].clic_en(click.x, click.y)) {
        accion_pendiente = AccionBot::MEDALLAS;
    }
    else if (botones[3].clic_en(click.x, click.y)) {
        accion_pendiente = AccionBot::VOLVER;
    }
}