#include "BrochaPantallas.h"
#include "freeglut.h"
#include <string>
#include "ETSIDI.h"

void BrochaPantallas::limpiar_pantalla(ColorTextos color) {
    glClearColor(color.r, color.g, color.b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void BrochaPantallas::dibujar_texto(const std::string& texto, Coordenada pos, ColorTextos color) {
    glPushAttrib(GL_ALL_ATTRIB_BITS); //guardamos todos los estados

    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);

    glColor3f(color.r, color.g, color.b);
    glRasterPos2f(pos.x, pos.y);
    for (char c : texto)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);

    glPopAttrib();  // Restauramos todo
}

void BrochaPantallas::dibujar_barra_carga(float progreso, Coordenada desde, Coordenada hasta, ColorTextos color) {
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    float ancho = hasta.x - desde.x;
    float progreso_x = desde.x + ancho * progreso;

    glColor3f(color.r, color.g, color.b);
    glBegin(GL_QUADS);
    glVertex2f(desde.x, desde.y);
    glVertex2f(progreso_x, desde.y);
    glVertex2f(progreso_x, hasta.y);
    glVertex2f(desde.x, hasta.y);
    glEnd();

    glPopAttrib();
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

void BrochaPantallas::dibujar_recuadro(Coordenada desde, Coordenada hasta, ColorTextos color, float opacidad) {
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_LIGHTING);

    glColor4f(color.r, color.g, color.b, opacidad);

    glBegin(GL_QUADS);
    glVertex2f(desde.x, desde.y);
    glVertex2f(hasta.x, desde.y);
    glVertex2f(hasta.x, hasta.y);
    glVertex2f(desde.x, hasta.y);
    glEnd();

    glPopAttrib();
}

void BrochaPantallas::configurar_proyeccion_pantalla(double num) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-num, num, -num, num); // sistema de coordenadas original para pantallas
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    return button == GLUT_LEFT_BUTTON && state == GLUT_UP;
}


void BrochaPantallas::insertarimagen(const char* direccion){
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND); //Habilita blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Configura c�mo se mezcla
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(direccion).id);
    glDisable(GL_LIGHTING);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    double xcoord1{ -2.0 }, xcoord2{ 2.0 };
    double ycoord1{ -2.0 }, ycoord2{ 2.0 };
    glTexCoord2d(0, 1); glVertex2d(xcoord1, ycoord1);
    glTexCoord2d(1, 1); glVertex2d(xcoord2, ycoord1);
    glTexCoord2d(1, 0); glVertex2d(xcoord2, ycoord2);
    glTexCoord2d(0, 0); glVertex2d(xcoord1, ycoord2);
    glEnd();
    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
}