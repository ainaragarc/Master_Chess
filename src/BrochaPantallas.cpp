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

void BrochaPantallas::dibujar_barra_carga(float progreso, float x1, float y1, float x2, float y2, float r, float g, float b) {
    float ancho = x2 - x1;
    float progreso_x = x1 + ancho * progreso;

    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(progreso_x, y1);
    glVertex2f(progreso_x, y2);
    glVertex2f(x1, y2);
    glEnd();
}

Coordenada BrochaPantallas::convertir_click_a_opengl(int x, int y) {
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);

    float glX = static_cast<float>(x) / w * 2.0f - 1.0f;
    float glY = static_cast<float>(h - y) / h * 2.0f - 1.0f;

    return { glX, glY };
}

bool BrochaPantallas::es_clic_izquierdo(int button, int state) {
    return button == GLUT_LEFT_BUTTON && state == GLUT_DOWN;
}