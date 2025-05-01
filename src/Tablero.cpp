#include "Tablero.h"
#include "freeglut.h"
#include <iostream>

//Por ahora no se usa pero puede ser util en el futuro
enum Columna :char { A = 'A', B = 'B', C = 'C', D = 'D', E = 'E' };

void Tablero::display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    dibuja();

    glutSwapBuffers();
}

void Tablero::dibuja() {
    bool white = true;

    for (int i = 0; i < TamTablero; i++) {
        for (int j = 0; j < TamTablero; j++) {
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
        if (TamTablero % 2 == 0)
            white = !white;
    }
}

void Tablero::init() {
    glClearColor(0.2f, 0.1f, 0.2f, 1.0f); // Fondo verde
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Aquí definimos una proyección ortográfica 2D
    gluOrtho2D(-3.0, 3.0, -3.0, 3.0);
    glMatrixMode(GL_MODELVIEW);
}


void Tablero::mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        
        get_Pos(x, y);

        if (posicion.Y >= 0 && posicion.Y < TamTablero && posicion.X >= 0 && posicion.X < TamTablero) {
            char letraColumna = 'A' + posicion.X;
            std::cout << "Has hecho clic en la casilla (" << letraColumna << ", " << posicion.Y << ")\n";
        }
    }
    
}

Posicion Tablero::get_Pos(int x, int y) {
    // Convertir coordenadas de pantalla (x, y) a coordenadas de OpenGL
    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    float glX = (float)x / windowWidth * 6.0f - 3.0f;
    float glY = (float)(windowHeight - y) / windowHeight * 6.0f - 3.0f;

    // Traducir coordenadas OpenGL a casilla de tablero
    posicion.X = (glX - BOARD_OFFSET) / TamCuadrado;
    posicion.Y = (glY - BOARD_OFFSET) / TamCuadrado;

    return posicion;
}