#include "PantallaMedallas.h"
#include "BrochaPantallas.h"
#include "freeglut.h"
#include "ETSIDI.h"

PantallaMedallas::PantallaMedallas(GestorPantallas* gestor) : gestor(gestor) {
    botones.push_back({ "VOLVEr", Coordenada{-0.5f,  0.4f}, Coordenada{0.3f,  0.50f } });
}


void PantallaMedallas::dibuja() {
	
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND); //Habilita blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Configura cómo se mezcla
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
    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
   // ColorTextos colorTexto = ColorTextos(1.0f, 1.0f, 1.0f);
   /* for (auto& b : botones)
        b.dibujar();*/
}

void PantallaMedallas::raton(int button, int state, int x, int y) {
    if (!BrochaPantallas::es_clic_izquierdo(button, state)) return;

    Coordenada click = BrochaPantallas::convertir_click_a_opengl(x, y);

    if (botones[0].clic_en(click.x, click.y)) {
        
    }
}