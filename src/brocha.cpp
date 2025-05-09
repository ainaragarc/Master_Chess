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
    // Aquí definimos una proyección ortográfica 2D
    gluOrtho2D(-longitudVentana, longitudVentana, -longitudVentana, longitudVentana);
    glMatrixMode(GL_MODELVIEW);
}

//void Brocha::mouse(int button, int state, int x, int y, const Brocha& brocha) {
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//
//        get_Pos(x, y, brocha);
//
//        if (posicion.Fila >= 0 && posicion.Fila < numCasillas && posicion.Columna >= 0 && posicion.Columna < numCasillas) {
//            char letraColumna = 'A' + posicion.Columna;
//            std::cout << "Has hecho clic en la casilla (" << letraColumna << ", " << posicion.Fila << ")\n";
//        }
//    }
//
//}

//Posicion Brocha::get_Pos(int x, int y, const Brocha& brocha) {
//    // Convertir coordenadas de pantalla (x, y) a coordenadas de OpenGL
//    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
//    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
//
//    float glX = (float)x / windowWidth * 2 * longitudVentana - longitudVentana;
//    float glY = (float)(windowHeight - y) / windowHeight * 2 * longitudVentana - longitudVentana;
//
//    // Traducir coordenadas OpenGL a casilla de tablero
//    float BOARDOFFSET = -((numCasillas * TamCuadrado) / 2.0f);
//    posicion.Columna = (int)std::floor(glX - BOARDOFFSET) / TamCuadrado;
//    posicion.Fila = (int)std::floor(glY - BOARDOFFSET) / TamCuadrado;
//
//    return posicion;
//}