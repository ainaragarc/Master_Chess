#include "Mundo.h"
#include "freeglut.h"
#include <cmath>

void Mundo::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();  // Restablece la matriz de modelo-vista
	

	//AQUI IRAN TODAS LAS FUNCIONES DIBUJA
	glDisable(GL_LIGHTING); // Opcional: desactiva iluminación si no la necesitas para 2D

	BROCHA.dibuja_t(TABLERO.get_numCas(), TABLERO.get_TamCuad()); // Dibuja el tablero
	BROCHA.dibuja_ini(TABLERO.get_TamCuad(), TABLERO.get_numCas(),TABLERO.get_piezas_B());//Dibuja las piezas de inicio
	BROCHA.dibuja_ini(TABLERO.get_TamCuad(), TABLERO.get_numCas(), TABLERO.get_piezas_N());
    if (!casillas_posibles.empty()) {
        BROCHA.resalta_casillas(casillas_posibles, TABLERO.get_TamCuad(), TABLERO.get_numCas());
    }
	glEnable(GL_LIGHTING);

}

void Mundo::mueve()
{
	//Todo lo que se mueva en el mundo o interactue entre sí

}
void Mundo::inicializa()
{
	BROCHA.init_t(BROCHA.get_longVent());
	TABLERO.inicializa_piezas();
	//TABLERO.PRUEBADEMOVIMIENTO();
	
	TABLERO.Pruebapiezas();
}

void Mundo::gestionar_click(int button, int state, int x, int y) {
    if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
        return;

    //convertimos clic en pantalla a casilla del tablero
    int fila, columna;  
    Posicion clic = BROCHA.get_Pos(x, y,
        BROCHA.get_longVent(),
        TABLERO.get_TamCuad(),
        TABLERO.get_numCas(),
        fila, columna);

    //comprobamos que el clic está dentro del tablero
    if (fila < 0 || fila >= TABLERO.get_numCas() ||
        columna < 0 || columna >= TABLERO.get_numCas()) {
        std::cout << "Ninguna casilla seleccionada\n";
        pieza_seleccionada = nullptr;
        casillas_posibles.clear();
        esperando_segundo_click = false;
        return;
    }

    Posicion destino{ fila, columna };

    // SEGUNDO CLIC: intento de movimiento
    if (esperando_segundo_click && pieza_seleccionada) {
        for (const auto& pos : casillas_posibles) { //compara el clic con las posiciones validas
            if (pos.Fila == destino.Fila && pos.Columna == destino.Columna) {
                std::cout << "Movimiento válido\n";
                //eliminamos pieza(comer) si existe en la casilla destino
                if (TABLERO.hay_pieza(destino)) {
                    TABLERO.comer_pieza(destino);
                }
                pieza_seleccionada->mueve(destino);
                //realizamos el cambio de turno si el movimiento es valido
                turno_actual = cambiar_turno(turno_actual);
                std::cout << "Turno actual: " << a_string(turno_actual) << "\n";
                pieza_seleccionada = nullptr;
                casillas_posibles.clear();
                esperando_segundo_click = false;
                return;
            }
        }
        std::cout << "Movimiento inválido\n";
        pieza_seleccionada = nullptr;
        casillas_posibles.clear();
        esperando_segundo_click = false;
        return;
    }

    // PRIMER CLIC: seleccionar pieza propia 
    std::vector<Pieza*> piezas = es_blanco(turno_actual) //evaluamos el turno actual
        ? TABLERO.get_piezas_B()
        : TABLERO.get_piezas_N();

    for (auto& p : piezas) {
        if (p->get_posicion().Fila == fila && p->get_posicion().Columna == columna) {
            pieza_seleccionada = p; //guardamos la pieza encontrada
            casillas_posibles = p->posiciones_posibles();
            esperando_segundo_click = true;

            std::cout << "Pieza seleccionada. Posibles movimientos:\n";
            for (const auto& pos : casillas_posibles)
                std::cout << "- (" << pos.Fila << ", " << pos.Columna << ")\n";
            return;
        }
    }

    std::cout << "No hay pieza seleccionada\n"; 
}
