#include "PantallaMedallas.h"
#include "BrochaPantallas.h"
#include "freeglut.h"
#include "ETSIDI.h"

PantallaMedallas::PantallaMedallas(GestorPantallas* gestor) : gestor(gestor) {
    botones.push_back({ "<- VOLVER", Coordenada{0.4f, -0.8f}, Coordenada{1.0f, -0.7f} });
}


void PantallaMedallas::dibuja() {
    // Dibuja fondo
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Fondo_medallas.png").id);
    glDisable(GL_LIGHTING);

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    double xcoord1{ -1.0 }, xcoord2{ 1.0 };
    double ycoord1{ -1.0 }, ycoord2{ 1.0 };
    glTexCoord2d(0, 1); glVertex2d(xcoord1, ycoord1);
    glTexCoord2d(1, 1); glVertex2d(xcoord2, ycoord1);
    glTexCoord2d(1, 0); glVertex2d(xcoord2, ycoord2);
    glTexCoord2d(0, 0); glVertex2d(xcoord1, ycoord2);
    glEnd();

    // Restaurar estado para que los botones se vean bien
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
    glDisable(GL_LIGHTING); // por si afecta color del botón

    // Dibujo botón
    for (auto& b : botones)
        b.dibujar();
}



void PantallaMedallas::raton(int button, int state, int x, int y) {
    if (!BrochaPantallas::es_clic_izquierdo(button, state)) return;

    Coordenada click = BrochaPantallas::convertir_click_a_opengl(x, y);

    if (botones[0].clic_en(click.x, click.y)) {
        
    }
}