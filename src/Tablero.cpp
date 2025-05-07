#include "Tablero.h"
#include "freeglut.h"
#include <iostream>

//Por ahora no se usa pero puede ser util en el futuro
enum Columna :char { A = 'A', B = 'B', C = 'C', D = 'D', E = 'E' };

void Tablero::mouse(int button, int state, int x, int y, const Brocha& brocha) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        
        get_Pos(x, y, brocha);

        if (posicion.Fila >= 0 && posicion.Fila < brocha.getNumCasillas() && posicion.Columna >= 0 && posicion.Columna < brocha.getNumCasillas()) {
            char letraColumna = 'A' + posicion.Columna;
            std::cout << "Has hecho clic en la casilla (" << letraColumna << ", " << posicion.Fila << ")\n";
        }
    }
    
}

Posicion Tablero::get_Pos(int x, int y, const Brocha& brocha) {
    // Convertir coordenadas de pantalla (x, y) a coordenadas de OpenGL
    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    float glX = (float)x / windowWidth * 2 * brocha.get_longitudVentana() - brocha.get_longitudVentana();
    float glY = (float)(windowHeight - y) / windowHeight * 2 * brocha.get_longitudVentana() - brocha.get_longitudVentana();

    // Traducir coordenadas OpenGL a casilla de tablero
    posicion.Columna = (int)std::floor(glX - brocha.getBoardOffset()) / brocha.getTamCuadrado();
    posicion.Fila = (int)std::floor(glY - brocha.getBoardOffset()) / brocha.getTamCuadrado();

    return posicion;
}