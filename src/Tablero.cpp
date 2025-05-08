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
//enum Columna :char { A = 'A', B = 'B', C = 'C', D = 'D', E = 'E' };

//void Tablero::mouse(int button, int state, int x, int y, const Brocha& brocha) {
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//        
//        get_Pos(x, y, brocha);
//
//        if (posicion.Fila >= 0 && posicion.Fila < brocha.getNumCasillas() && posicion.Columna >= 0 && posicion.Columna < brocha.getNumCasillas()) {
//            char letraColumna = 'A' + posicion.Columna;
//            std::cout << "Has hecho clic en la casilla (" << letraColumna << ", " << posicion.Fila << ")\n";
//        }
//    }
//    
//}

//Posicion Tablero::get_Pos(int x, int y, const Brocha& brocha) {
//    // Convertir coordenadas de pantalla (x, y) a coordenadas de OpenGL
//    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
//    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
//
//    float glX = (float)x / windowWidth * 2 * brocha.get_longitudVentana() - brocha.get_longitudVentana();
//    float glY = (float)(windowHeight - y) / windowHeight * 2 * brocha.get_longitudVentana() - brocha.get_longitudVentana();
//
//    // Traducir coordenadas OpenGL a casilla de tablero
//    posicion.Columna = (int)std::floor(glX - brocha.getBoardOffset()) / brocha.getTamCuadrado();
//    posicion.Fila = (int)std::floor(glY - brocha.getBoardOffset()) / brocha.getTamCuadrado();
//
//    return posicion;
//}

Tablero::Tablero() : numCasillas(5), TamCuadrado(1.0f) {
    BOARD_OFFSET = -((numCasillas * TamCuadrado) / 2.0f);
}
void Tablero::inicializa_piezas() {
    piezas_B.push_back(new Peon());//reservo memoria para un peon (subclase de pieza) y lo guardo en vector de blancas
    piezas_B.back()->set_color(BLANCO);//Lo defino como Blanco
    piezas_B.back()->set_tipo();

    piezas_B.push_back(new Caballo());//reservo memoria para un Caballo
    piezas_B.back()->set_color(BLANCO);
    piezas_B.back()->set_tipo();

    piezas_B.push_back(new Torre());//reservo memoria para un Torre
    piezas_B.back()->set_color(BLANCO);
    piezas_B.back()->set_tipo();

    piezas_B.push_back(new Alfil());//reservo memoria para una Alfin
    piezas_B.back()->set_color(BLANCO);
    piezas_B.back()->set_tipo();

    piezas_B.push_back(new Rey());//reservo memoria para una Rey
    piezas_B.back()->set_color(BLANCO);
    piezas_B.back()->set_tipo();

    piezas_B.push_back(new Dama());//reservo memoria para un Reina
    piezas_B.back()->set_color(BLANCO);
    piezas_B.back()->set_tipo();


    piezas_N.push_back(new Peon());//reservo memoria para un peon (subclase de pieza) y lo guardo en vector de blancas
    piezas_N.back()->set_color(NEGRO);//Lo defino como Negro
    piezas_N.back()->set_tipo();

    piezas_N.push_back(new Caballo());//reservo memoria para un Caballo
    piezas_N.back()->set_color(NEGRO);
    piezas_N.back()->set_tipo();

    piezas_N.push_back(new Torre());//reservo memoria para un Torre
    piezas_N.back()->set_color(NEGRO);
    piezas_N.back()->set_tipo();

    piezas_N.push_back(new Alfil());//reservo memoria para una Alfil
    piezas_N.back()->set_color(NEGRO);
    piezas_N.back()->set_tipo();

    piezas_N.push_back(new Rey());//reservo memoria para una Rey
    piezas_N.back()->set_color(NEGRO);
    piezas_N.back()->set_tipo();

    piezas_N.push_back(new Dama());//reservo memoria para un Dama
    piezas_N.back()->set_color(NEGRO);
    piezas_N.back()->set_tipo();

    //Prueba:
    for (auto i : piezas_B) {
        cout << "Pieza: " << static_cast<int>(i->get_tipo()) << " Color: " << static_cast<int>(i->get_color()) << endl;
    }
    cout << "\n";
    for (auto i : piezas_N) {
        cout << "Pieza: " << static_cast<int>(i->get_tipo()) << " Color: " << static_cast<int>(i->get_color())<< endl;
    }

}