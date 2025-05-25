#include "BrochaPantallas.h"
#include "freeglut.h"

void BrochaPantallas::limpiar_pantalla(ColorTextos color) {
    glClearColor(color.r, color.g, color.b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void BrochaPantallas::dibujar_texto(const std::string& texto, Coordenada pos, ColorTextos color) {
    glColor3f(color.r, color.g, color.b);
    glRasterPos2f(pos.x, pos.y);
    for (char c : texto)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
}

void BrochaPantallas::dibujar_barra_carga(float progreso, Coordenada desde, Coordenada hasta, ColorTextos color) {
    float ancho = hasta.x - desde.x;
    float progreso_x = desde.x + ancho * progreso;

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_QUADS);
    glVertex2f(desde.x, desde.y);
    glVertex2f(progreso_x, desde.y);
    glVertex2f(progreso_x, hasta.y);
    glVertex2f(desde.x, hasta.y);
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