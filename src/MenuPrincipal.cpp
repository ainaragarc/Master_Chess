#include "MenuPrincipal.h"
#include "BrochaPantallas.h"

MenuPrincipal::MenuPrincipal(GestorPantallas* gestor) : gestor(gestor) {
    float ancho_total = 0.6f;
    float alto_boton = 0.15f;
    float margen = 0.15f;
    float x1 = -ancho_total / 2.0f;
    float x2 = ancho_total / 2.0f;

    float y_top = 0.0f;

    botones.push_back({ "NUEVA PARTIDA",{ x1, y_top },{ x2, y_top + alto_boton } });
    botones.push_back({ "SALIR",{ x1, y_top - 1 * (alto_boton + margen) }, { x2, y_top - 1 * (alto_boton + margen) + alto_boton } });
}

void MenuPrincipal::dibuja() {
    BrochaPantallas::configurar_proyeccion_pantalla(1.0);

    BrochaPantallas::limpiar_pantalla(ColorTextos(0.1f, 0.1f, 0.2f));
    ColorTextos colorTexto = ColorTextos(1.0f, 1.0f, 1.0f);
    BrochaPantallas::insertarimagen("imagenes/inicio.png", 1.0, 1.0, 1.0, 1.0);
    
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



