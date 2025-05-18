#include "MenuPrincipal.h"
#include "BrochaPantallas.h"

MenuPrincipal::MenuPrincipal(GestorPantallas* gestor) : gestor(gestor) {
    botones.push_back({ "Nueva Partida", -0.3f,  0.1f, 0.3f,  0.25f });
    botones.push_back({ "Salir",         -0.3f, -0.2f, 0.3f, -0.05f });
}

void MenuPrincipal::dibuja() {
    BrochaPantallas::limpiar_pantalla(0.15f, 0.15f, 0.15f);
    BrochaPantallas::dibujar_texto("MENU PRINCIPAL", -0.3f, 0.2f);
    for (auto& b : botones)
        b.dibujar();
}

void MenuPrincipal::raton(int button, int state, int x, int y) {
    if (!BrochaPantallas::es_clic_izquierdo(button, state)) return;

    Coordenada click = BrochaPantallas::convertir_click_a_opengl(x, y);

    if (botones[0].clic_en(click.x, click.y)) {
        accion_pendiente = AccionMenu::NUEVA_PARTIDA;
    }
    else if (botones[1].clic_en(click.x, click.y)) {
        accion_pendiente = AccionMenu::SALIR;
    }
}



