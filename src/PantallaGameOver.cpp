#include "PantallaGameOver.h"
#include "BrochaPantallas.h"
#include "freeglut.h"
#include "Mundo.h"

PantallaGameOver::PantallaGameOver(const std::string& ganador) {
    mensaje = ganador;
    botones.push_back({ "<- VOLVER", Coordenada{0.4f, -0.8f}, Coordenada{1.0f, -0.7f} });
   
}


void PantallaGameOver::dibuja() {
   
    if (mensaje == "BLANCAS") {
        BrochaPantallas::insertarimagen("imagenes/Victoria para blancas.png");
    }
    if (mensaje == "NEGRAS") {
        BrochaPantallas::insertarimagen("imagenes/Victoria para negras.png");
    }
    // Restaurar estado para que los botones se vean bien
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
    glDisable(GL_LIGHTING); // por si afecta color del botón
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