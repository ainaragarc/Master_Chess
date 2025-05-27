
#include "PantallaGameOver.h"
#include "BrochaPantallas.h"
#include "freeglut.h"
#include "Mundo.h"

PantallaGameOver::PantallaGameOver(const std::string& ganador) {
    mensaje = ganador;
   
}

void PantallaGameOver::dibuja() {
   
    if (mensaje == "BLANCAS") {
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND); //Habilita blending
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Configura cómo se mezcla
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Victoria para blancas.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        double xcoord1{ -3.0 }, xcoord2{ 3.0 };
        double ycoord1{ -3.0 }, ycoord2{ 3.0 };
        glTexCoord2d(0, 1); glVertex2d(xcoord1, ycoord1);
        glTexCoord2d(1, 1); glVertex2d(xcoord2, ycoord1);
        glTexCoord2d(1, 0); glVertex2d(xcoord2, ycoord2);
        glTexCoord2d(0, 0); glVertex2d(xcoord1, ycoord2);
        glEnd();
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
    }
    if (mensaje == "NEGRAS") {
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND); //Habilita blending
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Configura cómo se mezcla
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Victoria para negras.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        double xcoord1{ -3.0 }, xcoord2{ 3.0 };
        double ycoord1{ -3.0 }, ycoord2{ 3.0 };
        glTexCoord2d(0, 1); glVertex2d(xcoord1, ycoord1);
        glTexCoord2d(1, 1); glVertex2d(xcoord2, ycoord1);
        glTexCoord2d(1, 0); glVertex2d(xcoord2, ycoord2);
        glTexCoord2d(0, 0); glVertex2d(xcoord1, ycoord2);
        glEnd();
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
    }
   
}

