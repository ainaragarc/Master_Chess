#include "PantallaCoronando.h"
#include "BrochaPantallas.h"

PantallaCoronando::PantallaCoronando(GestorPantallas* gestor) : gestor(gestor) {
    botones.push_back({ "CABALLO", Coordenada{-2.3f,  0.5f}, Coordenada{-0.3f,  1.2f} });
    botones.push_back({ "ALFIL",   Coordenada{  0.3f,  0.5f}, Coordenada{  2.3f,  1.2f} });
    botones.push_back({ "TORRE",   Coordenada{-2.3f, -0.8f}, Coordenada{-0.3f, -0.1f} });
    botones.push_back({ "DAMA",    Coordenada{  0.3f, -0.8f}, Coordenada{  2.3f, -0.1f} });
}

void PantallaCoronando::dibuja() {
    ColorTextos colorTexto = ColorTextos(1.0f, 1.0f, 1.0f);
    BrochaPantallas::dibujar_texto("SELECCIONA PIEZA PARA CORONAR", Coordenada{-2.2f, 3.f }, colorTexto);
    for (auto& b : botones)
        b.dibujar();
}

void PantallaCoronando::raton(int button, int state, int x, int y) {
    if (!BrochaPantallas::es_clic_izquierdo(button, state)) return;

    Coordenada click = BrochaPantallas::convertir_click_a_opengl(x, y);
    if (botones[0].clic_en(click.x, click.y)) {
        accion_pendiente = AccionCoronar::CABALLO;
    }
    else if (botones[1].clic_en(click.x, click.y)) {
        accion_pendiente = AccionCoronar::ALFIL;
    }
    else if (botones[2].clic_en(click.x, click.y)) {
        accion_pendiente = AccionCoronar::TORRE;
    }
    else if (botones[3].clic_en(click.x, click.y)) {
        accion_pendiente = AccionCoronar::DAMA;
    }
    
}