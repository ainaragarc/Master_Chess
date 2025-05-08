#include "brocha.h"
#include "freeglut.h"
#include <iostream>
#include "Tablero.h"

//const int Brocha::numCasillas = 5;
//const float Brocha::TamCuadrado = 1.0f;
//const float Brocha::BOARD_OFFSET = -((Brocha::numCasillas * Brocha::TamCuadrado) / 2.0f);

void Brocha::dibuja_t(Tablero& tablero) {

    bool white = true;

    for (int i = 0; i < tablero.numCasillas; i++) {
        for (int j = 0; j < tablero.numCasillas; j++) {
            if (white)
                glColor3f(1.0f, 1.0f, 1.0f); // Blanco
            else
                glColor3f(0.0f, 0.0f, 0.0f); // Negro

            glBegin(GL_QUADS);
            glVertex2f(j * tablero.TamCuadrado + tablero.BOARD_OFFSET, i * tablero.TamCuadrado + tablero.BOARD_OFFSET);
            glVertex2f((j + 1) * tablero.TamCuadrado + tablero.BOARD_OFFSET, i * tablero.TamCuadrado + tablero.BOARD_OFFSET);
            glVertex2f((j + 1) * tablero.TamCuadrado + tablero.BOARD_OFFSET, (i + 1) * tablero.TamCuadrado + tablero.BOARD_OFFSET);
            glVertex2f(j * tablero.TamCuadrado + tablero.BOARD_OFFSET, (i + 1) * tablero.TamCuadrado + tablero.BOARD_OFFSET);
            glEnd();

            white = !white;
        }
        if (tablero.numCasillas % 2 == 0)
            white = !white;
    }

}

void Brocha::init_t()
{
    glClearColor(0.2f, 0.1f, 0.2f, 1.0f); // Fondo morado
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Aquí definimos una proyección ortográfica 2D
    gluOrtho2D(-longitudVentana, longitudVentana, -longitudVentana, longitudVentana);
    glMatrixMode(GL_MODELVIEW);
}

void Brocha::mouse(int button, int state, int x, int y, const Tablero& tablero,const Brocha& brocha) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

        get_Pos(x, y, brocha,tablero);

        if (posicion.Fila >= 0 && posicion.Fila < tablero.getnumCasillas() && posicion.Columna >= 0 && posicion.Columna < tablero.getnumCasillas()) {
            char letraColumna = 'A' + posicion.Columna;
            std::cout << "Has hecho clic en la casilla (" << letraColumna << ", " << posicion.Fila << ")\n";
        }
    }

}

Posicion Brocha::get_Pos(int x, int y, const Brocha& brocha, const Tablero& tablero) {
    // Convertir coordenadas de pantalla (x, y) a coordenadas de OpenGL
    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    float glX = (float)x / windowWidth * 2 * brocha.get_longitudVentana() - brocha.get_longitudVentana();
    float glY = (float)(windowHeight - y) / windowHeight * 2 * brocha.get_longitudVentana() - brocha.get_longitudVentana();

    // Traducir coordenadas OpenGL a casilla de tablero
    posicion.Columna = (int)std::floor((glX - tablero.getBOARD_OFFSET()) / tablero.getTamCuadrado());
    posicion.Fila = (int)std::floor((glY - tablero.getBOARD_OFFSET()) / tablero.getTamCuadrado());


    return posicion;
}