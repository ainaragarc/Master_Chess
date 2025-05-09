#include "brocha.h"

void Brocha::dibuja_t(int numCasillas, float TamCuadrado) {
    float BOARD_OFFSET = -((numCasillas * TamCuadrado) / 2.0f);

    bool white = true;

    for (int i = 0; i < numCasillas; i++) {
        for (int j = 0; j < numCasillas; j++) {
            if (white)
                glColor3f(1.0f, 1.0f, 1.0f); // Blanco
            else
                glColor3f(0.0f, 0.0f, 0.0f); // Negro

            glBegin(GL_QUADS);
            glVertex2f(j * TamCuadrado + BOARD_OFFSET, i * TamCuadrado + BOARD_OFFSET);
            glVertex2f((j + 1) * TamCuadrado + BOARD_OFFSET, i * TamCuadrado + BOARD_OFFSET);
            glVertex2f((j + 1) * TamCuadrado + BOARD_OFFSET, (i + 1) * TamCuadrado + BOARD_OFFSET);
            glVertex2f(j * TamCuadrado + BOARD_OFFSET, (i + 1) * TamCuadrado + BOARD_OFFSET);
            glEnd();

            white = !white;
        }
        if (numCasillas % 2 == 0)
            white = !white;
    }

}

void Brocha::init_t(float longitudVentana)
{
    glClearColor(0.2f, 0.1f, 0.2f, 1.0f); // Fondo morado
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Aqu� definimos una proyecci�n ortogr�fica 2D
    gluOrtho2D(-longitudVentana, longitudVentana, -longitudVentana, longitudVentana);
    glMatrixMode(GL_MODELVIEW);
}