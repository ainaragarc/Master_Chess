#include "Tablero.h"
#include "freeglut.h"
#include <iostream>

//Por ahora no se usa pero puede ser util en el futuro
enum Columna :char { A = 'A', B = 'B', C = 'C', D = 'D', E = 'E' };

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