#include "PantallaSeleccionNivel.h"
#include "BrochaPantallas.h"

PantallaSeleccionNivel::PantallaSeleccionNivel(GestorPantallas* gestor) : gestor(gestor) {
    botones.push_back({ "NIVEL 1", Coordenada{-0.5f,  0.1f}, Coordenada{0.3f,  0.25f } });
    botones.push_back({ "NIVEL 2",Coordenada{-0.5f, -0.2f}, Coordenada{0.3f, -0.05f } });
    botones.push_back({ "NIVEL 3", Coordenada{-0.5f, -0.5f}, Coordenada{0.3f, -0.35f} });
    botones.push_back({ "MEDALLAS", Coordenada{-0.5f, -0.8f}, Coordenada{0.3f, -0.65f} });
}

void PantallaSeleccionNivel::dibuja() {
    BrochaPantallas::limpiar_pantalla(ColorTextos(0.15f, 0.15f, 0.15f));
    ColorTextos colorTexto = ColorTextos(1.0f, 1.0f, 1.0f);
    BrochaPantallas::dibujar_texto("SELECCIONA NIVEL", Coordenada{ -0.4f, 0.4f }, colorTexto);
    for (auto& b : botones)
        b.dibujar();
}

void PantallaSeleccionNivel::raton(int button, int state, int x, int y) {
    if (!BrochaPantallas::es_clic_izquierdo(button, state)) return;

    Coordenada click = BrochaPantallas::convertir_click_a_opengl(x, y);

    if (botones[0].clic_en(click.x, click.y)) {
        accion_pendiente = AccionNivel :: Nivel1;
    }
    else if (botones[1].clic_en(click.x, click.y)) {
        accion_pendiente = AccionNivel :: Nivel2;
    }
    else if (botones[2].clic_en(click.x, click.y)) {
        accion_pendiente = AccionNivel::Nivel3;
    }
}