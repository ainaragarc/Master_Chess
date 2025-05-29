#include "PantallaSeleccionNivel.h"
#include "BrochaPantallas.h"

PantallaSeleccionNivel::PantallaSeleccionNivel(GestorPantallas* gestor) : gestor(gestor) {
    float ancho_total = 0.6f;
    float alto_boton = 0.15f;
    float margen = 0.05f;
    float x1 = -ancho_total / 2.0f;
    float x2 = ancho_total / 2.0f;

    float y_top = 0.25f;

    botones.push_back({ "NIVEL 1",{ x1, y_top },{ x2, y_top + alto_boton } });
    botones.push_back({ "NIVEL 2",{ x1, y_top - 1 * (alto_boton + margen) }, { x2, y_top - 1 * (alto_boton + margen) + alto_boton } });
    botones.push_back({ "NIVEL 3", { x1, y_top - 2 * (alto_boton + margen) }, { x2, y_top - 2 * (alto_boton + margen) + alto_boton } });
    botones.push_back({ "<- VOLVER", { x1, y_top - 3 * (alto_boton + margen) }, { x2, y_top - 3 * (alto_boton + margen) + alto_boton } });

}

void PantallaSeleccionNivel::dibuja() {
    BrochaPantallas::configurar_proyeccion_pantalla(1.0);

    BrochaPantallas::limpiar_pantalla(ColorTextos(0.1f, 0.1f, 0.2f));
    ColorTextos colorTexto = ColorTextos(1.0f, 1.0f, 1.0f);
    BrochaPantallas::insertarimagen("imagenes/nivel.png", 1.0, 1.0, 1.0, 1.0);
    //BrochaPantallas::dibujar_texto("SELECCIONA NIVEL", Coordenada{ -0.4f, 0.4f }, colorTexto);
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
    else if (botones[3].clic_en(click.x, click.y)) {
        accion_pendiente = AccionNivel:: VOLVER;
    }
}