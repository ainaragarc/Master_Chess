#include "BrochaPantallas.h"
#include "freeglut.h"

void BrochaPantallas::limpiar_pantalla(float r, float g, float b) {
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void BrochaPantallas::dibujar_texto(const std::string& texto, float x, float y, float r, float g, float b) {
    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    for (char c : texto)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
}