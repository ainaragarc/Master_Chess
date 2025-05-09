#include "Tablero.h"
#include "peon.h"
#include "alfil.h"
#include "caballo.h"
#include "dama.h"
#include "rey.h"
#include "torre.h"
#include "freeglut.h"
#include<vector>
#include <iostream>

//Por ahora no se usa pero puede ser util en el futuro
enum Columna :char { A = 'A', B = 'B', C = 'C', D = 'D', E = 'E' };

void Tablero::mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        
        get_Pos(x, y);

        if (posicion.Fila >= 0 && posicion.Fila < numCasillas && posicion.Columna >= 0 && posicion.Columna < numCasillas) {
            char letraColumna = 'A' + posicion.Columna;
            std::cout << "Has hecho clic en la casilla (" << letraColumna << ", " << posicion.Fila << ")\n";
        }
    }
    
}

Posicion Tablero::get_Pos(int x, int y) {
    // Convertir coordenadas de pantalla (x, y) a coordenadas de OpenGL
    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    float glX = (float)x / windowWidth * 2 * longitudVentana - longitudVentana;
    float glY = (float)(windowHeight - y) / windowHeight * 2 * longitudVentana - longitudVentana;

    // Traducir coordenadas OpenGL a casilla de tablero
    float BOARDOFFSET = -((numCasillas * TamCuadrado) / 2.0f);
    posicion.Columna = (int)std::floor(glX - BOARDOFFSET) / TamCuadrado;
    posicion.Fila = (int)std::floor(glY - BOARDOFFSET) / TamCuadrado;

    return posicion;
}

void Tablero::inicializa_piezas() {

    añadir_piezas_B(piezas_B, new Peon());
    añadir_piezas_B(piezas_B, new Caballo());
    añadir_piezas_B(piezas_B, new Torre());
    añadir_piezas_B(piezas_B, new Alfil());
    añadir_piezas_B(piezas_B, new Rey());
    añadir_piezas_B(piezas_B, new Dama());

    añadir_piezas_N(piezas_N, new Peon());
    añadir_piezas_N(piezas_N, new Caballo());
    añadir_piezas_N(piezas_N, new Torre());
    añadir_piezas_N(piezas_N, new Alfil());
    añadir_piezas_N(piezas_N, new Rey());
    añadir_piezas_N(piezas_N, new Dama());
    //Prueba:
    for (auto i : piezas_B) {
        cout << "Pieza: " << static_cast<int>(i->get_tipo()) << " Color: " << static_cast<int>(i->get_color()) << " Cantidad: " << i->get_cantidad() << endl;
    }
    cout << "\n";
    for (auto i : piezas_N) {
        cout << "Pieza: " << static_cast<int>(i->get_tipo()) << " Color: " << static_cast<int>(i->get_color()) << " Cantidad: " << i->get_cantidad() << endl;
    }

}

//funcion para limpiar mas el codigo de inicializa pieza
void Tablero::añadir_piezas_B(vector<Pieza*>& equipo, Pieza* pieza) {
    equipo.push_back(pieza);
    equipo.back()->set_color(BLANCO);//inicializamos el color de la pieza como blanco
    equipo.back()->set_tipo();
    equipo.back()->set_cantidad();//inicializamos la cantidad de cada pieza

}

void Tablero::añadir_piezas_N(vector<Pieza*>& equipo, Pieza* pieza) {
    equipo.push_back(pieza);
    equipo.back()->set_color(NEGRO);//inicializamos el color de la pieza como negro
    equipo.back()->set_tipo();
    equipo.back()->set_cantidad();

}